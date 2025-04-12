#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i = 0;
	int bytes = 0;
	char *ret = malloc(10000);
	char c;

	if (BUFFER_SIZE < 0)
		return (free(ret), NULL);
	while (bytes = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1) > 0)
	{
		ret[i++] = c;
		if (c == '\n')
			break ;
	}
	if ((ret[i - 1] && !bytes) || bytes == -1)
	{
		free(ret);
		return NULL;
	}
	ret[i] = '\0';
	return ret;
}

int main(){
	int fd = open("cenas", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	printf("ola");
	printf("ola");
	printf("ola");
	printf("ola");
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	printf("ola");
	printf("ola");
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}
