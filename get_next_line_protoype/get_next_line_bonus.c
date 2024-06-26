/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:12:33 by acuva-nu          #+#    #+#             */
/*   Updated: 2022/12/09 18:40:38 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
	{
		i = 0;
		while (fd > 0 && fd <= FOPEN_MAX && i < BUFFER_SIZE)
			buffer[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	if (!buffer[fd][0])
		buffer[fd][read(fd, buffer[fd], BUFFER_SIZE)] = 0;
	line = reader(fd, buffer[fd]);
	return (line);
}
