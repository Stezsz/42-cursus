#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i = 0;
	if(!str)
		return 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t i = 0, j = 0;

	res = malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!res)
		return (NULL);
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\n')
		res[j++] = s2[i++];
	if (s2[i] == '\n')
		res[j++] = '\n';
	res[j] = 0;
	free(s1);
	return res;
}

void	bufflord(char *str)
{
	size_t i = 0, j = 0;

	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
		str[j++] = str[i++];
	str[j] = 0;
}

char	*reader(int fd, char *buffer)
{
	char	*line = NULL;

	while(buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return NULL;
		if (buffer[ft_strlen(buffer) + 1] == '\n')
		{
			bufflord(buffer);
			break ;
		}
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	return (reader(fd, buffer));
}
