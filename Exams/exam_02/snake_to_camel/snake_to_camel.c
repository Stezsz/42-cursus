#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar1(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	else if (c >= 'A' && c <= 'Z')
		c += 32;
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;

		while (av[1][i])
		{
			if (av[1][i] == '_')
			{
				i++;
				ft_putchar1(av[1][i]);
			}
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
}
