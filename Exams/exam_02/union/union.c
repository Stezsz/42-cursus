#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_doup(char *str, char c, int pos)
{

	pos--;
	while (pos >= 0)
	{
		if (str[pos] == c)
			return 1;
		pos--;
	}
	return 0;
}

int	main(int ac, char **av)
{
	int i = 0;
	int j = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check_doup(av[1], av[1][i], i) == 0)
				ft_putchar(av[1][i]);
			i++;
		}

		while (av[2][j])
		{
			if (check_doup(av[1], av[2][j] , i) == 0 && check_doup(av[2], av[2][j], j) == 0)
				ft_putchar(av[2][j]);
			j++;
		}
	}
	write(1, "\n", 1);
}
