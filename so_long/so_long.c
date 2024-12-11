/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:41:39 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 17:41:39 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_program	game;

	if (ac != 2)
	{
		write(1, "Usage: ./so_long [file.ber]\n", 28);
		exit(1);
	}
	ft_bzero(&game, sizeof(t_program));
	check_map(av[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_free(&game, "Error: mlx_init failed.");
		exit(1);
	}
	new_window(&game);
	render_map(game);
	ft_printf("%s─────────────────── So Long! ───────────────────\n", YELLOW);
	game.moves = 0;
	mlx_hook(game.win, KEY_PRESS, 1L << 0, ft_input, &game);
	mlx_loop(game.mlx);
	return (0);
}

////////////////////////// 1.0 ///////////////////////////
//Valgrind ./so_long sem mapa - 0 leaks					//
//Valgrind ./so_long mapa vazio - 0 leaks				//
//Valgrind ./so_long mapa valido - 55 leaks				//
//Valgrind ./so_long mapa invalido - ind leaks			//
//////////////////////////////////////////////////////////
