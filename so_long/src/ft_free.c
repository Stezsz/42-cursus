/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:21:37 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/05 16:21:37 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_program *game, char *msg)
{
	int	i;

	if (game->map.map)
	{
		i = 0;
		while (game->map.map[i])
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
	}
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (ft_strcmp(msg, "Player Win!") == 0)
		ft_printf("%s──────────────── Player Win! ────────────────\n", GREEN);
	else
		ft_printf("%s%s\n", RED, msg);
	exit(0);
}
