/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:29:42 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 22:29:42 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_rectangular(char *file)
{
	ft_printf("%sError: Map is not rectangular. %s\n", RED, file);
	exit(1);
}

void	error_characters(char *file)
{
	ft_printf("%sError: Invalid characters in map. %s\n", RED, file);
	exit(1);
}

void	error_player(char *file)
{
	ft_printf("%sError: Map need one player. %s\n", RED, file);
	exit(1);
}

void	error_walls(char *file)
{
	ft_printf("%sError: Map is not surrounded by walls. %s\n", RED, file);
	exit(1);
}

void	error_ecp(char *file)
{
	ft_printf("%sError: Player or Exit or Collectible not found!. %s\n",
		RED, file);
	exit(1);
}
