#include <unistd.h>

void ft_putnbr(int n)
{
	char num;
	if (n >= 10)
		ft_putnbr(n / 10);
	num = (n % 10) + '0';
	write(1, &num, 1);
}

int ft_atoi(char *c)
{
	int result = 0;

	while (*c >= '0' && *c <= '9')
	{
		result = result * 10 + *c - '0';
		c++;
	}
	return result;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 1;
		while (i < 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(ft_atoi(av[1]));
			write(1, " = ", 3);
			int result = i * ft_atoi(av[1]);
			ft_putnbr(result);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
