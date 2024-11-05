#include <unistd.h>

void	ft_putnbr(int i)
{
	if (i > 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		i += 48;
		write(1, &i, 1);
	}
}

int	main(int ac, char **av)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 5 == 0 && i % 3 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}
