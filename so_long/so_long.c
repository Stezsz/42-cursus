/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:34:40 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/02 13:34:40 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_program	game;

	if (ac != 2)
		exit(EXIT_FAILURE);
	check_map(av[1], &game);
	return (EXIT_SUCCESS);
}
