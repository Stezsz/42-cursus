/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:09:23 by strodrig          #+#    #+#             */
/*   Updated: 2024/05/18 16:38:25 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadd_hex(unsigned long int nbr, char Xx, int *printed)
{
	unsigned long int		blen;
	char		*base;

	blen = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < blen)
		ft_putchar(base[nbr % blen], printed);
	else
	{
		ft_putadd_hex(nbr / blen, Xx, printed);
		ft_putadd_hex(nbr % blen, Xx, printed);
	}
}

void	ft_putadd(void	*add, int	*printed)
{
	unsigned long int	ptr;

	ptr = (unsigned long int)add;
	ft_putstr("0x", printed);
	ft_putadd_hex(ptr, 'x', printed);
}
