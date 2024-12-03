/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:43:09 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 16:43:09 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_program *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	exit(EXIT_FAILURE);
}
