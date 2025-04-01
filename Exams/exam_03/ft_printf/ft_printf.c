#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i = -1;

	if (!str)
		str = "(null)";
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(unsigned int nb, int base)
{
	return (nb / base ? ft_putnbr(nb / base, base) : 0) +
		ft_putchar("0123456789abcdef"[nb % base]);
}

int	print_d(int nb)
{
	int	count = 0;

	if (nb < 0)
	{
		count += ft_putchar('-');
		if (nb == -2147483648)
			return (count + ft_putstr("2147483648"));
		nb = -nb;
	}
	return (count + ft_putnbr((unsigned int)nb, 10));
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		count = 0;
	int		i = -1;

	if (!str)
		return (0);
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == 'd')
				count += print_d(va_arg(ap, int));
			else if (str[i] == 'x')
				count += ft_putnbr(va_arg(ap, unsigned int), 16);
			else if (str[i] == 's')
				count += ft_putstr(va_arg(ap, char *));
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(ap);
	return (count);
}
