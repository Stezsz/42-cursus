/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:50:36 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 12:50:36 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_input(int key, void *param)
{
	t_program	*game;

	game = (t_program *)param;
	if (key == ESC_KEY)
		ft_free(game, "Closing the game!");
	else if (key == UP_KEY)
		ft_move_player(game, 0, -1);
	else if (key == DOWN_KEY)
		ft_move_player(game, 0, 1);
	else if (key == LEFT_KEY)
		ft_move_player(game, -1, 0);
	else if (key == RIGHT_KEY)
		ft_move_player(game, 1, 0);
	mlx_clear_window(game->mlx, game->win_ptr);
	ft_render(*game);
	return (0);
}
