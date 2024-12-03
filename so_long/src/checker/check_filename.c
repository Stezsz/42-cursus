/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:17:58 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/03 13:17:58 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_filename(const char *file_name, const char *to_find)
{
	size_t	to_find_len;
	size_t	file_name_len;

	to_find_len = ft_strlen(to_find);
	file_name_len = ft_strlen(file_name);
	while (file_name_len > to_find_len)
	{
		file_name++;
		file_name_len--;
	}
	return (ft_strcmp(file_name, to_find));
}
