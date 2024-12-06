/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:24:00 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/06 11:24:00 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(char **copy, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			ft_printf("%sError: Memory allocation failed\n", RED);
			exit(1);
		}
		i++;
	}
}

void	ft_free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
