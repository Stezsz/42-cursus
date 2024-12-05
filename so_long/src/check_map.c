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

void	error_extension(char *file)
{
	ft_printf("%sError: Invalid file extention. %s\n", RED, file);
	exit(1);
}

static void	check_dir(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		write(1, "Error: Invalid file\n", 20);
		exit(1);
	}
	close(fd);
}

void	check_map(char *file, t_program *game)
{
	check_dir(file);
	if (check_extension(file, ".ber") != 0)
		error_extension(file);
	ft_printf("First check passed: extension\n"); // Debug
	read_map(file, game);
	printf("Map read successfully\n"); // Debug
	if (check_rectangular(*game) != 0)
		error_rectangular(file);
	ft_printf("Second check passed: rectangular\n"); // Debug
	if (check_characters(*game) != 0)
		error_characters(file);
	ft_printf("Third check passed: chars\n"); // Debug
	if (check_player(*game) == 0)
		error_player(file);
	ft_printf("Fourth check passed: player\n"); // Debug
	if (check_walls(game) != 0)
		error_walls(file);
	ft_printf("Fifth check passed: walls\n"); // Debug
	if (check_ecp(*game) == 0)
		error_ecp(file);
	ft_printf("Sixth check passed: ecp\n"); // Debug
}
