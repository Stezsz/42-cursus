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
		ft_putchar((char)va_arg(args, int), printed);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), printed);
	else if (format == 'p')
		ft_putadd(va_arg(args, void *), printed);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), printed);
	else if (format == 'u')
		ft_putnbr_u(va_arg(args, int), printed);
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, int), format, printed);
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, int), format, printed);
	else if (format == '%')
		ft_putchar(format, printed);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			printed;

	if (!format)
		return (-1);
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

/*int	main(void)
{
	printf("-----------\n");
	ft_printf("%p\n", (void *)0);
	printf("%p\n", (void *)0);
	printf("-----------\n");
	ft_printf("%i\n", 2147483647);
	printf("%i\n", 2147483647);
	printf("-----------\n");
	ft_printf("%i\n", (int)-2147483648);
	printf("%i\n", (int)-2147483648);
	printf("-----------\n");
	ft_printf("%x\n", 0);
	printf("%x\n", 0);
	printf("-----------\n");
	ft_printf("%s\n", "");
	printf("%s\n", "");
	printf("-----------\n");
	ft_printf("%i\n", ft_printf(NULL));
	// printf("%i",printf(NULL));
	printf("-----------\n");
	ft_printf("%%\n");
	printf("%%\n");
	printf("-----------\n");
}*/
