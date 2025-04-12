#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int i = 0;
	int len = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_putdigits(long long nbr, int base)
{
	int len = 0;

	if (nbr < 0)
	{
		nbr *= -1;
		len += write(1, "-", 1);
	}
	if (nbr >= base)
		len += ft_putdigits((nbr / base), base);
	len += ft_putchar("0123456789abcdef"[nbr % base]);
	return len;
}

int ft_printf(const char *format, ... )
{
	int i = 0;
	int len = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else if (format[i] == '%' && format[i + 1])
		{
			if (format[i] == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'd')
				len += ft_putdigits(va_arg(args, int), 10);
			else if (format[i] == 'x')
				len += ft_putdigits(va_arg(args, unsigned int), 16);
		}
		i++;
	}
	va_end(args);
	return len;
}

int main()
{
	ft_printf("%s ", "test1");
	printf("%s \n", "test1");
	ft_printf("test2 ");
	printf("test2\n");
	ft_printf("%d ", 42);
	printf("%d\n", 42);
	ft_printf("%x ", 10);
	printf("%x\n", 10);
}




