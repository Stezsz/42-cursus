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
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	game->map.row = map_len(fd);
	close(fd);
	game->map.map = malloc(sizeof(char *) * (game->map.row + 1));
	if (!game->map.map)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	game->map.map[game->map.row] = 0;
	fd = open(file_name, O_RDONLY);
	while (i < game->map.row)
		game->map.map[i++] = get_next_line(fd);
	close(fd);
}
