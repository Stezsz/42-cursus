#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	str_capitalizer(char *str)
{
	int i = 0;

	while (str[i])
	{
		if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t') && (str[i] >= 'a' && str[i] <= 'z'))
			ft_putchar(str[i] - 32);
		else if (i > 0 && str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] != ' ' && str[i - 1] != '\t')
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
