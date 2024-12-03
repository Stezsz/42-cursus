/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:28:24 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 13:28:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	error_filename(char *file_name)
{
	ft_printf("%s%s: Invalid file extention.\n",
		RED, file_name);
	exit(EXIT_FAILURE);
}
