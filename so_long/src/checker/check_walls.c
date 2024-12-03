/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:00:03 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 17:00:03 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_walls(t_program *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.col = ft_strlen(game->map.map[0]) - 1;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (i == 0 || i == game->map.row - 1)
			{
				if (game->map.map[i][j] != '1')
					return (1);
			}
			if (j == 0 || j == game->map.col - 1)
			{
				if (game->map.map[i][j] != '1')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
