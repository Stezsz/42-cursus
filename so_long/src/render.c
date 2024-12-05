/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:16:13 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/05 17:16:13 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_path(char c, int can_exit)
{
	char	*path;

	(void)can_exit;
	path = NULL;
	if (c == WALL)
		path = "assets/wall.xpm";
	else if (c == PLAYER)
		path = "assets/player.xpm";
	else if (c == COLLECTIBLE)
		path = "assets/collectible.xpm";
	else if (c == EXIT)
	{
		if (can_exit)
			path = "assets/exit_open.xpm";
		else
			path = "assets/exit.xpm";
	}
	return (path);
}

void	render_image(t_program game, int x, int y)
{
	char	*path;

	if (game.map.collectibles == 0)
		game.can_exit = 1;
	path = ft_get_path(game.map.map[x][y], game.can_exit);
	if (path)
	{
		game.img = mlx_xpm_file_to_image(game.mlx, path,
				&game.img_size, &game.img_size);
		mlx_put_image_to_window(game.mlx, game.win, game.img,
			y * SQUARE, x * SQUARE);
		mlx_destroy_image(game.mlx, game.img);
	}
}

void	render_map(t_program game)
{
	int	x;
	int	y;

	x = 0;
	game.img_size = SQUARE;
	while (game.map.map[x])
	{
		y = 0;
		while (game.map.map[x][y] != '\n' && game.map.map[x][y])
		{
			render_image(game, x, y);
			y++;
		}
		x++;
	}
}
