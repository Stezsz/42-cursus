#include <unistd.h>

void	ft_putchar(char c, int n)
{
	while (n >= 0)
	{
		write(1, &c, 1);
		n--;
	}
}


int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				ft_putchar(av[1][i], av[1][i] - 97);
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				ft_putchar(av[1][i], av[1][i] - 65);
			else
				ft_putchar(av[1][i], 0);
			i++;
		}
	}
	write(1, "\n", 1);
}
