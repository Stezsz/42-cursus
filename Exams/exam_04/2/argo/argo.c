#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

//added
#include <stdlib.h>

// Estrutura para representar um valor JSON (int, string ou mapa)
typedef struct	json {
	enum {
		MAP,     // Objeto JSON: {"key": value, ...}
		INTEGER, // Número inteiro
		STRING   // String entre aspas
	} type;
	union {
		struct {
			struct pair	*data; // Array de pares chave-valor
			size_t		size;  // Número de pares no mapa
		} map;
		int	integer;  // Valor inteiro
		char	*string; // String (sem as aspas)
	};
}	json;

// Par chave-valor para objetos JSON
typedef struct	pair {
	char	*key;   // Chave (sempre string)
	json	value;  // Valor (pode ser qualquer tipo JSON)
}	pair;



//Added
int		argo(json *dst, FILE *stream);
int		parser(json *dst, FILE *stream);
int		parse_int(json *dst, FILE *stream);
int		parse_string(json *dst, FILE *stream);
int 	parse_map(json *dst, FILE *stream);


void	free_json(json j);
int	argo(json *dst, FILE *stream);

// Verifica o próximo caractere sem consumi-lo do stream
int	peek(FILE *stream)
{
	int	c = getc(stream);  // Lê o caractere
	ungetc(c, stream);     // Coloca de volta no buffer
	return c;              // Retorna o caractere
}

// Imprime mensagem de erro para token inesperado
void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

// Consome um caractere específico se ele for o próximo
int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream); // Consome o caractere
		return 1;           // Sucesso
	}
	return 0; // Caractere não encontrado
}

// Espera um caractere específico, senão gera erro
int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream); // Imprime erro
	return 0;
}

// Libera memória alocada para estrutura JSON recursivamente
void	free_json(json j)
{
	switch (j.type)
	{
		case MAP: // Para mapas, libera cada par chave-valor
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);        // Libera chave
				free_json(j.map.data[i].value); // Libera valor (recursivo)
			}
			free(j.map.data); // Libera array de pares
			break ;
		case STRING:
			free(j.string); // Libera string
			break ;
		default: // INTEGER não precisa liberar
			break ;
	}
}

// Serializa estrutura JSON de volta para formato texto
void	serialize(json j)
{
	switch (j.type)
	{
		case INTEGER:
			printf("%d", j.integer); // Imprime número
			break ;
		case STRING:
			putchar('"'); // Aspas de abertura
			for (int i = 0; j.string[i]; i++)
			{
				// Escapa caracteres especiais
				if (j.string[i] == '\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"'); // Aspas de fechamento
			break ;
		case MAP:
			putchar('{'); // Abre objeto
			for (size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(','); // Vírgula entre pares
				// Serializa chave como string
				serialize((json){.type = STRING, .string = j.map.data[i].key});
				putchar(':'); // Dois pontos
				serialize(j.map.data[i].value); // Serializa valor (recursivo)
			}
			putchar('}'); // Fecha objeto
			break ;
	}
}




// Parser principal: identifica tipo de valor e chama parser específico
int parser(json *dst, FILE *stream)
{
	int	c;

	c = peek(stream); // Verifica próximo caractere
	if (c == '"')        // Se começa com aspas, é string
		return (parse_string(dst, stream));
	else if (isdigit(c) || c == '-') // Se é dígito ou sinal negativo, é número
		return (parse_int(dst, stream));
	else if (c == '{')   // Se começa com chave, é objeto
		return (parse_map(dst, stream));
	else
	{
		unexpected(stream); // Token não reconhecido
		return (-1);
	}
}

// Parseia um número inteiro
int parse_int(json *dst, FILE *stream)
{
	long long n = 0;
	int sign = 1;
	int c = peek(stream);

	if (c == '-') {
		sign = -1;
		getc(stream); // consume '-'
	}

	c = peek(stream);
	if (!isdigit(c)) {
		unexpected(stream);
		return -1;
	}

	while (isdigit(c = peek(stream))) {
		n = n * 10 + (getc(stream) - '0');
	}

	dst->type = INTEGER;
	dst->integer = n * sign;
	return 1;
}

// Parseia uma string JSON (entre aspas, com escape)
int parse_string(json *dst, FILE *stream)
{
    size_t size = 0;
    size_t capacity = 16;
    char *buffer = malloc(capacity);
	char c;

	if (!expect(stream, '"')) {
        free(buffer);
		return (-1);
    }

	while (1)
	{
		c = getc(stream);
		if (c == EOF)
		{
            free(buffer);
			unexpected(stream);
			return (-1);
		}
		if (c == '"')
			break ;
		if (c == '\\')
		{
			c = getc(stream);
			if (c != '"' && c != '\\') {
                // Invalid escape according to subject
                free(buffer);
                unexpected(stream);
                return -1;
            }
		}
        if (size + 1 >= capacity) {
            capacity *= 2;
            buffer = realloc(buffer, capacity);
        }
		buffer[size++] = c;
	}
	buffer[size] = '\0';
	dst->type = STRING;
	dst->string = buffer;
	return (1);
}

// Helper to free a partially built map during parsing failure
static void free_map_items(pair *items, size_t size) {
    if (!items) return;
    for (size_t i = 0; i < size; i++) {
        free(items[i].key);
        free_json(items[i].value);
    }
    free(items);
}

int parse_map(json *dst, FILE *stream)
{
    pair *items = NULL;
    size_t size = 0;
    json key;

    if (!expect(stream, '{'))
        return -1;

    if (accept(stream, '}')) { // Empty map {}
        dst->type = MAP;
        dst->map.size = 0;
        dst->map.data = NULL;
        return 1;
    }

    while (1) {
        items = realloc(items, sizeof(pair) * (size + 1));
        if (!items) return -1; // Malloc failure

        if (parse_string(&key, stream) == -1) {
            free_map_items(items, size);
            return -1;
        }
        if (!expect(stream, ':')) {
            free(key.string);
            free_map_items(items, size);
            return -1;
        }
        if (parser(&items[size].value, stream) == -1) {
            free(key.string);
            free_map_items(items, size);
            return -1;
        }
        items[size].key = key.string;
        size++;

        if (accept(stream, '}')) // End of map
            break;
        if (!expect(stream, ',')) { // Must be a comma before next element
            free_map_items(items, size);
            return -1;
        }
    }

    dst->type = MAP;
    dst->map.size = size;
    dst->map.data = items;
    return 1;
}


// Função principal do parser JSON
int argo(json *dst, FILE *stream)
{
	return (parser(dst, stream)); // Delega para parser principal
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	if (!stream) {
		printf("Error: Could not open file %s\n", filename);
		return 1;
	}
	json file;
    // Initialize to prevent freeing garbage on failure
	memset(&file, 0, sizeof(json));

	if (argo(&file, stream) != 1)
	{
		// On failure, argo should have freed any memory it allocated internally
		// before returning -1. The 'file' struct itself is on the stack.
		// The original free_json(file) was buggy.
		fclose(stream);
		return 1;
	}
	serialize(file);
	free_json(file); // Free memory on success
	fclose(stream);
	return 0;
}
