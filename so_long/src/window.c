/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:39:18 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 11:39:18 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_program *game)
{
	ft_free(game, "Window closed!");
	return (EXIT_SUCCESS);
}

void	ft_new_window(t_program *game)
{
	game->win_ptr = mlx_new_window(game->mlx, game->map.col * 32,
			game->map.row * 32, "so_long");
	mlx_hook(game->win_ptr, WIN_CLOSE, 0, ft_close, game);
}
