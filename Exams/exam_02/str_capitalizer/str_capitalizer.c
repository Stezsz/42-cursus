#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	str_capitalizer(char *av)
{
	int i = 0;

	while (av[i])
	{
		if ((i == 0 || av[i - 1] == ' ' || av[i - 1] == '\t') && (av[i] >= 'a' && av[i] <= 'z'))
			ft_putchar(av[i] - 32);
		else if (i > 0 && av[i - 1] != ' ' && av[i - 1] != '\t' && (av[i] >= 'A' && av[i] <= 'Z'))
			ft_putchar(av[i] + 32);
		else
			ft_putchar(av[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		int i = 1;

		while (i <= ac)
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}

	}
	else
		write(1, "\n", 1);
}
