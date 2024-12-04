/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:34:40 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/02 13:34:40 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_program	game;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long <file name>\n");
		exit(EXIT_FAILURE);
	}
	check_map(av[1], &game);
	game.mlx = mlx_init();
	ft_new_window(&game);
	ft_render(game);
	mlx_hook(game.win_ptr, 2, 0, *ft_input, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
