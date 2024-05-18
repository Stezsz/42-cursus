/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:37:20 by strodrig          #+#    #+#             */
/*   Updated: 2024/05/18 15:40:26 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *printed)
{
	if (s == NULL)
		ft_putstr("(null)", printed);
	while (s && *s)
	{
		ft_putchar(*s, printed);
		s++;
	}
}
