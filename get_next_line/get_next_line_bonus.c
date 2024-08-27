/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:56:27 by strodrig          #+#    #+#             */
/*   Updated: 2024/07/22 12:10:38 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || fd > FOPEN_MAX)
	{
		i = 0;
		while (fd > 0 && fd <= FOPEN_MAX && i < BUFFER_SIZE)
			buffer[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	if (!buffer[fd][0])
	{
		int bytesread = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytesread <= 0)
			return (NULL);
		buffer[fd][bytesread] = 0;
	}
	line = reader(fd, buffer[fd]);
	return (line);
}
