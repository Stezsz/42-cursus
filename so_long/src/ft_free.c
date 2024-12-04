/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:41:42 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 11:41:42 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_program *game, char *msg)
{
	int	i;

	i = 0;
	while (i < game->map.row)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	mlx_destroy_window(game->mlx, game->win_ptr);
	if (ft_strcmp(msg, "Player won!") == 0)
		ft_printf("\n%s%s\n", GREEN,
			"⊱ ──────────────── Congratulations! You won! ──────────────── ⊰");
	else
		ft_printf("\n%s%s\n", RED, msg);
	exit(EXIT_SUCCESS);
}
