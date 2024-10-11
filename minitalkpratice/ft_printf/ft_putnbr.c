/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:16 by strodrig          #+#    #+#             */
/*   Updated: 2024/09/25 13:47:38 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *printed)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-', printed);
		nb = -n;
	}
	else
		nb = n;
	if (nb < 10)
		ft_putchar(nb + '0', printed);
	else
	{
		ft_putnbr(nb / 10, printed);
		ft_putnbr(nb % 10, printed);
	}
}
