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

static int	map_len(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (len);
}

static char	*remove_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		line[len - 1] = '\0';
	if (len > 1 && (line[len - 2] == '\r'))
		line[len - 2] = '\0';
	return (line);
}

void	read_map(char *file, t_program *game)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sError: No such file or directory.\n", RED);
		exit(1);
	}
	game->map.rows = map_len(fd);
	close(fd);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map)
	{
		ft_printf("%sError: Malloc failed\n", RED);
		exit(1);
	}
	game->map.map[game->map.rows] = 0;
	fd = open(file, O_RDONLY);
	while (i < game->map.rows)
	{
		game->map.map[i++] = remove_newline(get_next_line(fd));
	}
	close(fd);
}
