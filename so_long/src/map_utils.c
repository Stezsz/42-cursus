/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:04:28 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/09 13:04:28 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_len(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (len);
}

char	*remove_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		line[len - 1] = '\0';
	if (len > 1 && (line[len - 2] == '\r'))
		line[len - 2] = '\0';
	return (line);
}
