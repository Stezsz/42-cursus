/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:15:24 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/05 00:15:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_program *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.cols = ft_strlen(game->map.map[0]);
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (i == 0 || i == game->map.rows - 1)
			{
				if (game->map.map[i][j] != WALL)
					return (1);
			}
			else if (j == 0 || j == game->map.cols - 1)
			{
				if (game->map.map[i][j] != WALL)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
