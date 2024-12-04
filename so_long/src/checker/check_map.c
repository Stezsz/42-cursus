/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:42:52 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 11:42:52 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map(char *file_name, t_program *game)
{
	int	fd;

	fd = open(file_name, O_DIRECTORY);
	if (fd != -1)
		exit(EXIT_FAILURE);
	if (check_filename(file_name, ".ber") != 0)
		error_filename(file_name);
	get_map(file_name, game);
	if (check_rectangular(*game) != 0)
		error_rectangular(game, file_name);
	if (check_walls(game) != 0)
		error_walls(game, file_name);
	if (check_elements(game) != 0)
		error_elements(game, file_name);
}
