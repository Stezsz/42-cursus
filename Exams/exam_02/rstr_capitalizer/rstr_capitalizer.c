#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rstr_capitalizer(char *av)
{
	int i = 0;

	while (av[i])
	{
		if ((av[i] >= 'a' && av[i] <= 'z') && (av[i + 1] == ' ' || av[i + 1] == '\t' || av[i + 1] == '\0'))
			ft_putchar(av[i] - 32);
		else if ((av[i] >= 'A' && av[i] <= 'Z') && (av[i + 1] != ' ' && av[i + 1] != '\t' && av[i + 1] != '\0'))
			ft_putchar(av[i] + 32);
		else
			ft_putchar(av[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 1;

		while (i < ac)
		{
			rstr_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}

// 56 - 8
// 88 - 8
