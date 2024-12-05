/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:44:07 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 23:44:07 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	check_characters(t_program game)
{
	int	row;
	int	col;

	row = 0;
	while (game.map.map[row])
	{
		col = 0;
		while (game.map.map[row][col] != '\n' && game.map.map[row][col] != '\0')
		{
			if (!in_set(game.map.map[row][col], "01PCE"))
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}
