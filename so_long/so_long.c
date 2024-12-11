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

void	free_resources(t_program *game)
{
	int	i;

	i = 0;

	if (game->map.map)
	{
		while (i < game->map.rows)
		{
			if (game->map.map[i])
				free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
	}
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
	}
	free(game->mlx);
}

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
//Valgrind ./so_long mapa valido - 0 leaks				//
//Valgrind ./so_long mapa invalido - 0 leaks			//
//////////////////////////////////////////////////////////
