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
	int	n;

	if (fscanf(stream, "%d", &n) == 1) // Lê inteiro usando fscanf
	{
		dst->type = INTEGER;
		dst->integer = n;
		return (1); // Sucesso
	}
	unexpected(stream);
	return (-1); // Erro
}

// Parseia uma string JSON (entre aspas, com escape)
int parse_string(json *dst, FILE *stream)
{
	char	buffer[4096]; // Buffer para armazenar string
	char	c;
	int		i;

	if (!expect(stream, '"')) // Espera aspas de abertura
		return (-1);
	i = 0;
	while (1)
	{
		c = getc(stream);
		if (c == EOF)
		{
			unexpected(stream);
			return (-1);
		}
		if (c == '"') // Aspas de fechamento
			break ;
		if (c == '\\') // Caractere de escape
		{
			c = getc(stream); // Lê próximo caractere
			if (c == EOF)
			{
				unexpected(stream);
				return (-1);
			}
			// Nota: aceita qualquer caractere após \, incluindo \" e \'
		}
		buffer[i++] = c; // Adiciona ao buffer
	}
	buffer[i] = '\0'; // Termina string
	dst->type = STRING;
	dst->string = strdup(buffer); // Copia para heap
	return (1);
}

// Parseia um objeto JSON: {"key1": value1, "key2": value2, ...}
int parse_map(json *dst, FILE *stream)
{
	pair	*items; // Array de pares chave-valor
	size_t	size;   // Número de pares
	json	key;    // Chave temporária

	if (!expect(stream, '{')) // Espera chave de abertura
		return (-1);
	items = NULL;
	size = 0;
	while (!accept(stream, '}')) // Enquanto não encontra chave de fechamento
	{
		// Expande array para novo par
		items = realloc(items, sizeof(pair) * (size + 1));
		// Parseia chave (deve ser string)
		if (parse_string(&key, stream) == -1)
		{
			free(items);
			return (-1);
		}
		if (!expect(stream, ':')) // Espera dois pontos
		{
			free(key.string);
			free(items);
			return (-1);
		}
		// Parseia valor (pode ser qualquer tipo)
		if (parser(&items[size].value, stream) == -1)
		{
			free(key.string);
			free(items);
			return (-1);
		}
		items[size].key = key.string; // Armazena chave
		size++;
		// Aceita vírgula opcional, mas deve ter '}' se não há vírgula
		if (!accept(stream, ',') && peek(stream) != '}')
		{
			unexpected(stream);
			free(items);
			return (-1);
		}
	}
	dst->type = MAP;
	dst->map.size = size;
	dst->map.data = items;
	return (1);
}

// Função principal do parser JSON
int argo(json *dst, FILE *stream)
{
	return (parser(dst, stream)); // Delega para parser principal
}

int	main(int argc, char **argv)
{
	if (argc != 2) // Precisa do nome do arquivo
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r"); // Abre arquivo para leitura
	if (!stream)
		return 1;
	json	file = {0}; // Inicializa estrutura
	if (argo (&file, stream) != 1) // Se parsing falha
	{
		fclose(stream);
		return 1;
	}
	fclose(stream);
	serialize(file); // Imprime JSON formatado
	printf("\n");
	free_json(file); // Libera memória após uso
	return 0;
}
