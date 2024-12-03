/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:37:04 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 13:37:04 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_map(char *file_name, t_program *game)
{
	int		fd;
	int		result;
	int		line_count;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sError\n", RED);
		exit(EXIT_FAILURE);
	}

	line_count = 0;
	while ((result = get_next_line(fd, &line)) > 0)
	{
		game->map[line_count] = line;
		line_count++;
	}
	if (result == -1)
	{
		ft_printf("%sError\n", RED);
		exit(EXIT_FAILURE);
	}
	game->map[line_count] = NULL;
	close(fd);
}
