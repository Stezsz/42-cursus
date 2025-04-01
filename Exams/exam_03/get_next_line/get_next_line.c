#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	char	*ret;
	char	c;
	int		i = 0;
	int		bytes = 0;

	if (fd < 0)
		return (NULL);
	ret = malloc(BUFFER_SIZE + 1);
	if (!ret)
		return (NULL);
	while ((bytes = read(fd, &c, 1)) > 0)
	{
		ret[i++] = c;
		if (c == '\n')
			break;
	}
	if (i == 0 || bytes < 0)
	{
		free(ret);
		return (NULL);
	}
	ret[i] = '\0';
	return (ret);
}

int main(int argc, char **argv)
{
	int		fd = 0;
	char	*line;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (fd > 0)
		close(fd);
	return (0);
}
