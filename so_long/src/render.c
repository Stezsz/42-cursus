/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:03:58 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 12:03:58 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_get_sprite(char c, int can_exit)
{
	if (c == WALL)
		return ("./sprites/wall.xpm");
	else if (c == PLAYER)
		return ("./sprites/player.xpm");
	else if (c == EXIT && can_exit == 0)
		return ("./sprites/exit.xpm");
	else if (c == EXIT && can_exit == 1)
		return ("./sprites/exit_open.xpm");
	else if (c == COLLECTIBLE)
		return ("./sprites/collectible.xpm");
	else if (c == FLOOR)
		return ("./sprites/floor.xpm");
	return (NULL);
}

static void	render_sprite(t_program game, int x, int y)
{
	char	*path;

	if (game.map.collectibles == 0)
		game.can_exit = 1;
	path = ft_get_sprite(game.map.map[x][y], game.can_exit);
	if (path)
	{
		game.img_ptr = mlx_xpm_file_to_image(game.mlx, path,
				&game.img_size, &game.img_size);
		mlx_put_image_to_window(game.mlx, game.win_ptr, game.img_ptr,
			y * 32, x * 32);
		mlx_destroy_image(game.mlx, game.img_ptr);
	}
}

void	ft_render(t_program game)
{
	int	x;
	int	y;

	x = 0;
	game.img_size = 32;
	while (game.map.map[x])
	{
		y = 0;
		while (game.map.map[x][y] != '\n' && game.map.map[x][y])
		{
			render_sprite(game, x, y);
			y++;
		}
		x++;
	}
}
