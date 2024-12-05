/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:18:49 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/05 16:18:49 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_program *game)
{
	ft_free(game, "Window closed");
	return (0);
}

void	new_window(t_program *game)
{
	int	width;
	int	height;

	width = game->map.cols * SQUARE;
	height = game->map.rows * SQUARE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	mlx_hook(game->win, WIN_CLOSE, 0, close_window, game);
}
