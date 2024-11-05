#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int n1 = atoi(av[1]);
		int n2 = atoi(av[2]);
		int n = n1;

		while (n > 0)
		{
			if (n1 % n == 0 && n2 % n == 0)
			{
				printf("%d", n);
				break ;
			}
			n--;
		}
	}
	printf("\n");
	return 0;
}
