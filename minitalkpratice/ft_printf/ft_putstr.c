/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:37:20 by strodrig          #+#    #+#             */
/*   Updated: 2024/09/25 13:47:40 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *printed)
{
	if (!s)
		ft_putstr("(null)", printed);
	while (s && *s)
	{
		ft_putchar(*s, printed);
		s++;
	}
}
