/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:00:15 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 17:00:15 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	count_element(t_program *game, char element)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.col)
		{
			if (game->map.map[i][j] == element)
				count++;
		}
	}
	return (count);
}

int	check_elements(t_program *game)
{
	int	player;
	int	exit;
	int	collect;

	player = count_element(game, PLAYER);
	exit = count_element(game, EXIT);
	collect = count_element(game, COLLECTIBLE);
	return (player != 1 || exit != 1 || collect < 1);
}
