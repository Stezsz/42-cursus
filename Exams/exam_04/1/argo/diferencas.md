# Diferenças entre given.c e argo.c

## given.c:
```c
// #include <malloc.h> // change this to <stdlib.h>
```

## argo.c:
```c
#include <stdlib.h>
```

---

## given.c:
```c
int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	json	file;
	if (argo (&file, stream) != 1)
	{
		free_json(file);
		return 1;
	}
	serialize(file);
	printf("\n");
}
```

## argo.c:
```c
int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	if (!stream)
		return 1;
	json	file = {0};
	if (argo (&file, stream) != 1)
	{
		fclose(stream);
		return 1;
	}
	fclose(stream);
	serialize(file);
	printf("\n");
	free_json(file);
	return 0;
}
```

---

## argo.c adiciona estas funções:

```c
int argo(json *dst, FILE *stream)
{
	return (parser(dst, stream));
}

int parser(json *dst, FILE *stream)
{
	int	c;

	c = peek(stream);
	if (c == '"')
		return (parse_string(dst, stream));
	else if (isdigit(c) || c == '-')
		return (parse_int(dst, stream));
	else if (c == '{')
		return (parse_map(dst, stream));
	else
	{
		unexpected(stream);
		return (-1);
	}
}

int parse_int(json *dst, FILE *stream)
{
	int	n;

	if (fscanf(stream, "%d", &n) == 1)
	{
		dst->type = INTEGER;
		dst->integer = n;
		return (1);
	}
	unexpected(stream);
	return (-1);
}

int parse_string(json *dst, FILE *stream)
{
	char	buffer[4096];
	char	c;
	int		i;

	if (!expect(stream, '"'))
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
		if (c == '"')
			break ;
		if (c == '\\')
		{
			c = getc(stream);
			if (c == EOF)
			{
				unexpected(stream);
				return (-1);
			}
		}
		buffer[i++] = c;
	}
	buffer[i] = '\0';
	dst->type = STRING;
	dst->string = strdup(buffer);
	return (1);
}

int parse_map(json *dst, FILE *stream)
{
	pair	*items;
	size_t	size;
	json	key;

	if (!expect(stream, '{'))
		return (-1);
	items = NULL;
	size = 0;
	while (!accept(stream, '}'))
	{
		items = realloc(items, sizeof(pair) * (size + 1));
		if (parse_string(&key, stream) == -1)
		{
			free(items);
			return (-1);
		}
		if (!expect(stream, ':'))
		{
			free(key.string);
			free(items);
			return (-1);
		}
		if (parser(&items[size].value, stream) == -1)
		{
			free(key.string);
			free(items);
			return (-1);
		}
		items[size].key = key.string;
		size++;
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
```
