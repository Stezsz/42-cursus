/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:42:52 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 11:42:52 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_map(char *file_name, t_program *game)
{
	int	fd;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	game->fd = fd;
}
