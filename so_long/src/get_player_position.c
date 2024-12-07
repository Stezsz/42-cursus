/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:37:05 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/05 22:37:05 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_collectibles(t_program *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.collectibles = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'C')
				game->map.collectibles++;
			j++;
		}
		i++;
	}
}

void	get_player_position(t_program *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map.map[row])
	{
		col = 0;
		while (game->map.map[row][col])
		{
			if (game->map.map[row][col] == PLAYER)
			{
				game->map.player.y = col;
				game->map.player.x = row;
				return ;
			}
			col++;
		}
		row++;
	}
}
