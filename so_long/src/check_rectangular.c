/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:37:07 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 23:37:07 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_program game)
{
	int	row;
	int	len;
	int	line_len;

	row = 0;
	line_len = ft_strlen(game.map.map[row]);
	while (game.map.map[row])
	{
		len = ft_strlen(game.map.map[row]);
		if (len != line_len)
			return (1);
		row++;
	}
	return (0);
}
