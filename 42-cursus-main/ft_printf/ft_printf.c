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

static void	check_type(va_list args, const char format, int *printed)
{
	if (format == 'c')
		ft_putchar((char)va_arg(args, int), printed); //
	else if (format == 's')
		ft_putstr(va_arg(args, char *), printed); //
	else if (format == 'p')
		ft_putadd(va_arg(args, void *), printed); //
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), printed); //
	else if (format == 'u')
		ft_putnbr_u(va_arg(args, int), printed); //
	else if (format == 'x')
		ft_putnbr_base();
	else if (format == 'X')
		ft_putnbr_base();
	/*else if (format == '%')
		ft_putchar();*/
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			printed;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_type(args, *format, &printed);
		}
		else
			ft_putchar(*format, &printed);
		format++;
	}
	va_end(args);
	return (printed);
}

int	main(void)
{
	ft_printf("%c", 's');
	printf(" %c\n", 's');
	ft_printf("%s", "banana");
	printf(" %s\n", "banana");
	ft_printf("%p", (void *)77);
	printf(" %p\n", (void *)77);
	ft_printf("%d", 2147483647);
	printf(" %d\n", 2147483647);
	ft_printf("%i", 1234);
	printf(" %i\n", 1234);
	ft_printf("%u", -123);
	printf(" %u\n", -123);
}
