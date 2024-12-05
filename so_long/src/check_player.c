/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:58:25 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 23:58:25 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_program game)
{
	int	p;
	int	i;
	int	j;

	i = 0;
	p = 0;
	while (game.map.map[i])
	{
		j = 0;
		while (game.map.map[i][j])
		{
			if (game.map.map[i][j] == PLAYER)
				p++;
			j++;
		}
		i++;
	}
	return (p == 1);
}
