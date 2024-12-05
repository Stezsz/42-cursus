/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:37:51 by strodrig          #+#    #+#             */
/*   Updated: 2024/12/04 22:37:51 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(const char *file, const char *ext)
{
	size_t	len;
	size_t	ext_len;

	len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	while (len > ext_len)
	{
		file++;
		len--;
	}
	return (ft_strcmp(file, ext));
}
