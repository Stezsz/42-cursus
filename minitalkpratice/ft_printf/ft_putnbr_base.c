/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:51:49 by strodrig          #+#    #+#             */
/*   Updated: 2024/09/25 13:47:33 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char Xx, int *printed)
{
	unsigned int	blen;
	char			*base;

	blen = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < blen)
		ft_putchar(base[nbr % blen], printed);
	else
	{
		ft_putnbr_base(nbr / blen, Xx, printed);
		ft_putnbr_base(nbr % blen, Xx, printed);
	}
}
