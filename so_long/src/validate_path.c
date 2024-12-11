/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:20:48 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/06 11:20:48 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y, t_program *game)
{
	if (x < 0 || y < 0 || x >= game->map.cols || y >= game->map.rows)
		return ;
	if (map[y][x] == WALL || map[y][x] == 'X')
		return ;
	if (map[y][x] == COLLECTIBLE)
		game->map.collectibles--;
	if (map[y][x] == EXIT)
	{
		game->can_exit = 1;
		return ;
	}
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

int	validate_path(t_map *map)
{
	char		**copy;
	t_program	game;

	copy = malloc(sizeof(char *) * map->rows);
	if (!copy)
		return (1);
	copy_map(copy, map);
	game.map = *map;
	game.map.collectibles = map->collectibles;
	game.can_exit = 0;
	flood_fill(copy, map->player.y, map->player.x, &game);
	ft_free_map(copy, map->rows);
	if (game.map.collectibles > 0 || game.can_exit == 0)
		return (1);
	return (0);
}
