#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

typedef struct	pair {
	char	*key;
	json	value;
}	pair;

void	free_json(json j);
int	argo(json *dst, FILE *stream);

// Forward declarations for parsing functions
static int parse_string(json *dst, FILE *stream);
static int parse_integer(json *dst, FILE *stream);
static int parse_map(json *dst, FILE *stream);

int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

static int parse_string(json *dst, FILE *stream)
{
	if (!expect(stream, '"'))
		return -1;
	
	char *str = malloc(1);
	if (!str)
		return -1;
	str[0] = '\0';
	size_t len = 0;
	size_t capacity = 1;
	
	int c;
	while ((c = getc(stream)) != EOF)
	{
		if (c == '"')
		{
			dst->type = STRING;
			dst->string = str;
			return 1;
		}
		
		if (c == '\\')
		{
			c = getc(stream);
			if (c == EOF)
			{
				free(str);
				unexpected(stream);
				return -1;
			}
			if (c != '"' && c != '\\')
			{
				free(str);
				printf("unexpected token '%c'\n", c);
				return -1;
			}
		}
		
		if (len + 1 >= capacity)
		{
			capacity *= 2;
			char *new_str = realloc(str, capacity);
			if (!new_str)
			{
				free(str);
				return -1;
			}
			str = new_str;
		}
		
		str[len++] = c;
		str[len] = '\0';
	}
	
	free(str);
	unexpected(stream);
	return -1;
}

static int parse_integer(json *dst, FILE *stream)
{
	int value;
	if (fscanf(stream, "%d", &value) != 1)
	{
		unexpected(stream);
		return -1;
	}
	
	dst->type = INTEGER;
	dst->integer = value;
	return 1;
}

static int parse_map(json *dst, FILE *stream)
{
	if (!expect(stream, '{'))
		return -1;
	
	dst->type = MAP;
	dst->map.data = NULL;
	dst->map.size = 0;
	
	// Check for empty map
	if (accept(stream, '}'))
		return 1;
	
	while (1)
	{
		// Parse key
		json key_json;
		if (parse_string(&key_json, stream) != 1)
		{
			free_json(*dst);
			return -1;
		}
		
		// Expect colon
		if (!expect(stream, ':'))
		{
			free_json(key_json);
			free_json(*dst);
			return -1;
		}
		
		// Parse value
		json value;
		if (argo(&value, stream) != 1)
		{
			free_json(key_json);
			free_json(*dst);
			return -1;
		}
		
		// Add pair to map
		dst->map.data = realloc(dst->map.data, (dst->map.size + 1) * sizeof(pair));
		if (!dst->map.data)
		{
			free_json(key_json);
			free_json(value);
			return -1;
		}
		
		dst->map.data[dst->map.size].key = key_json.string;
		dst->map.data[dst->map.size].value = value;
		dst->map.size++;
		
		// Check for comma or end
		if (accept(stream, '}'))
			break;
		
		if (!expect(stream, ','))
		{
			free_json(*dst);
			return -1;
		}
	}
	
	return 1;
}

int	argo(json *dst, FILE *stream)
{
	if (!dst || !stream)
		return -1;
	
	int c = peek(stream);
	
	if (c == '"')
		return parse_string(dst, stream);
	else if (isdigit(c) || c == '-')
		return parse_integer(dst, stream);
	else if (c == '{')
		return parse_map(dst, stream);
	else
	{
		unexpected(stream);
		return -1;
	}
}

void	free_json(json j)
{
	switch (j.type)
	{
		case MAP:
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);
				free_json(j.map.data[i].value);
			}
			free(j.map.data);
			break ;
		case STRING:
			free(j.string);
			break ;
		default:
			break ;
	}
}

void	serialize(json j)
{
	switch (j.type)
	{
		case INTEGER:
			printf("%d", j.integer);
			break ;
		case STRING:
			putchar('"');
			for (int i = 0; j.string[i]; i++)
			{
				if (j.string[i] == '\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"');
			break ;
		case MAP:
			putchar('{');
			for (size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(',');
				serialize((json){.type = STRING, .string = j.map.data[i].key});
				putchar(':');
				serialize(j.map.data[i].value);
			}
			putchar('}');
			break ;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	if (!stream)
		return 1;
	json	file;
	// Initialize file to avoid garbage when argo fails
	file.type = STRING;
	file.string = NULL;
	
	if (argo (&file, stream) != 1)
	{
		fclose(stream);
		return 1;
	}
	serialize(file);
	printf("\n");
	free_json(file);
	fclose(stream);
	return 0;
}