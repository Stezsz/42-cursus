/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:28:24 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 13:28:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	error_filename(char *file_name)
{
	ft_printf("%s%s: Invalid file extention.\n", RED, file_name);
	exit(EXIT_FAILURE);
}

void	error_walls(t_program *game, char *file_name)
{
	ft_printf("%s%s: Invalid wall configuration!\n", RED, file_name);
	free_map(game);
	exit(EXIT_FAILURE);
}

void	error_rectangular(t_program *game, char *file_name)
{
	ft_printf("%s%s: Map is not rectangular!\n", RED, file_name);
	free_map(game);
	exit(EXIT_FAILURE);
}

void	error_elements(t_program *game, char *file_name)
{
	ft_printf("%s%s: Map needs exactly 1 P, 1 E and ≥1 C\n", RED, file_name);
	free_map(game);
	exit(EXIT_FAILURE);
}
