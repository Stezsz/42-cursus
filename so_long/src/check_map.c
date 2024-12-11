/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:25:43 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 22:25:43 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_extension(t_program *game, char *file)
{
	ft_free(game, "Error: Invalid file extension.");
}

void	error_path(t_program *game, char *file)
{
	ft_free(game, "Error: Invalid map.");
}

static void	check_dir(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		write(1, "Error: Invalid file\n", 20);
		close(fd);
		exit(1);
	}
}

void	check_map(char *file, t_program *game)
{
	check_dir(file);
	if (check_extension(file, ".ber") != 0)
		error_extension(game, file);
	read_map(file, game);
	if (check_rectangular(*game) != 0)
		error_rectangular(game, file);
	if (check_characters(*game) != 0)
		error_characters(game, file);
	if (check_player(*game) == 0)
		error_player(game, file);
	if (check_walls(game) != 0)
		error_walls(game, file);
	if (check_ecp(*game) == 0)
		error_ecp(game, file);
	get_collectibles(game);
	get_player_position(game);
	if (validate_path(&game->map) != 0)
		error_path(game, file);
}
