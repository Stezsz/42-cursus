/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:29:42 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 22:29:42 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_rectangular(t_program *game, char *file)
{
	ft_free(game, "Error: Map is not rectangular.");
}

void	error_characters(t_program *game, char *file)
{
	ft_free(game, "Error: Invalid characters in map.");
}

void	error_player(t_program *game, char *file)
{
	ft_free(game, "Error: Map needs one player.");
}

void	error_walls(t_program *game ,char *file)
{
	ft_free(game, "Error: Map is not surrounded by walls.");
}

void	error_ecp(t_program *game, char *file)
{
	ft_free(game, "Error: Player or Exit or Collectible not found!");
}
