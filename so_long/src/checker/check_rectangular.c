/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:59:44 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 16:59:44 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_rectangular(t_program *game)
{
	int	i;
	int	len;

	len = ft_strlen(game->map.map[0]);
	i = 1;
	while (i < game->map.row)
	{
		if (ft_strlen(game->map.map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}
