/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:44:18 by strodrig          #+#    #+#             */
/*   Updated: 2024/05/18 17:47:21 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *printed)
{
	if (n < 10)
		ft_putchar(n + '0', printed);
	else
	{
		ft_putnbr(n / 10, printed);
		ft_putnbr(n % 10, printed);
	}
}
