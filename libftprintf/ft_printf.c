/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:23:43 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/19 14:23:43 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write (1, &str, 1);
		i++;
	}
	return (i);
}

int	ft_conver(va_list v1, const char format)
{
	int	char_printed;

	char_printed = 0;
	if (format == 'c')
		char_printed += ft_putchar(va_arg(v1, int));
	else if (format == 's')
		char_printed += ft_putstr(va_arg(v1, char *));
	else if (format == 'p')
		char_printed += ft_putp(va_arg(v1, uintptr_t));
	else if (format == 'd' || format == 'i')
		char_printed += ft_putnbr(va_arg(v1, int));
	else if (format == 'u')
		char_printed += ft_putunsigned(va_arg(v1, unsigned int));
	else if (format == 'x' || format == 'X')
		char_printed += ft_puthex(va_arg(v1, unsigned int), format);
	else if (format == '%')
		char_printed += ft_putchar('%');
	return (char_printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	v1;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(v1, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += ft_conver(v1, format[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(v1);
	return (char_printed);
}
