#include <unistd.h>

void	ft_putnbr(int c)
{
	if (c > 9)
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
	else
	{
		c += 48;
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	int i = 0;
	while (i <= ac)
		i++;
	ft_putnbr(i - 2);
	write(1, "\n", 1);
}
