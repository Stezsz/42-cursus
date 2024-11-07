#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int space = 0;

		while ((av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				space = 1;
			else
			{
				if(space == 1)
					write(1, "   ", 3);
				space = 0;
				ft_putchar(av[1][i]);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
