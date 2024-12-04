/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:53:50 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 12:53:50 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_player(t_program *game, int x, int y)
{
	if (game->map.map[game->map.player.y + y][game->map.player.x + x] == '1')
		return ;
	if (game->map.map[game->map.player.y + y][game->map.player.x + x] == 'E')
	{
		if (game->map.collectibles == 0)
			ft_free(game, "Player won!");
		else
			return ;
	}
	if (game->map.map[game->map.player.y + y][game->map.player.x + x] == 'C')
	{
		game->map.map[game->map.player.y + y][game->map.player.x + x] = '0';
		game->map.collectibles--;
	}
	game->map.map[game->map.player.y][game->map.player.x] = '0';
	game->map.player.x += x;
	game->map.player.y += y;
	game->mv_count++;
}
