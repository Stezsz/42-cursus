/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:30:33 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/05 17:30:33 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, void	*param)
{
	t_program	*game;

	game = (t_program *)param;
	if (key == 65307)
		ft_free(game, "Game closed by Player!");
	else if (key == 97 || key == 65361)
		move_left(game);
	else if (key == 119 || key == 65362)
		move_up(game);
	else if (key == 100 || key == 65363)
		move_right(game);
	else if (key == 115 || key == 65364)
		move_down(game);
	mlx_clear_window(game->mlx, game->win);
	render_map(*game);
	return (0);
}
