#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int space = 0;

		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				space = 1;
			else
			{
				if (space)
					write(1, "   ", 3);
				space = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
