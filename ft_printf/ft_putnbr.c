/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:16 by strodrig          #+#    #+#             */
/*   Updated: 2024/05/18 17:31:05 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *printed)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-', printed);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + '0', printed);
	else
	{
		ft_putnbr(nb / 10, printed);
		ft_putnbr(nb % 10, printed);
	}
}
