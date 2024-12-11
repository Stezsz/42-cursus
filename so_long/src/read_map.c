/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:48:07 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 22:48:07 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_file(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		perror("Error");
		exit(1);
	}
}

static void	allocate_map(t_program *game)
{
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map)
	{
		ft_free(game, "Error: Malloc failed.");
		exit(1);
	}
	game->map.map[game->map.rows] = 0;
}

static void	read_lines(int fd, t_program *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		game->map.map[i] = remove_newline(get_next_line(fd));
		if (!game->map.map[i])
		{
			close(fd);
			ft_free(game, "Error: Failed to read map line.");
			exit(1);
		}
		i++;
	}
}

void	read_map(char *file, t_program *game)
{
	int	fd;

	game->map.map = NULL;
	open_file(file, &fd);
	game->map.rows = map_len(fd);
	close(fd);
	if (game->map.rows == 0)
	{
		ft_free(game, "Error: Empty map file.");
		exit(1);
	}
	allocate_map(game);
	open_file(file, &fd);
	read_lines(fd, game);
	close(fd);
}
