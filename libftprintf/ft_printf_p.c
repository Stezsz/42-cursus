/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:44:44 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/26 14:44:44 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_p(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_put_p(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_p(n / 16);
		ft_put_p(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + '0'));
		else
			ft_putchar((n - 10 + 'a'));
	}
}

int	ft_putp(uintptr_t ptr)
{
	int	char_printed;

	char_printed = 0;
	char_printed += write(1, "0x", 2);
	if (ptr == 0)
		char_printed += write(1, "0", 1);
	else
	{
		ft_put_p(ptr);
		char_printed += len_p(ptr);
	}
	return (char_printed);
}
