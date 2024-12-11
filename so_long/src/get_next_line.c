/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:35:48 by strodrig          #+#    #+#             */
/*   Updated: 2024/08/31 12:59:01 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		i;
	int			bytesread;

	if (fd < 0 || fd > FOPEN_MAX)
	{
		i = 0;
		while (buffer[i])
			buffer[i++] = 0;
		return (NULL);
	}
	line = NULL;
	if (!buffer[0])
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (NULL);
		buffer[bytesread] = 0;
	}
	line = reader(fd, buffer);
	return (line);
}

/*int	main(void)
{
	int		fd = open("tester.txt", O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}*/
