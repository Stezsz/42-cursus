/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:12:33 by acuva-nu          #+#    #+#             */
/*   Updated: 2022/12/09 18:36:40 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
	{
		i = 0;
		while (buffer[i])
			buffer[i++] = 0;
		return (NULL);
	}
	line = NULL;
	if (!buffer[0])
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	line = reader(fd, buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("ola.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// }
