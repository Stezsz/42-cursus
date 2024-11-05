#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int start_word = 0;
		int end_word = 0;

		while (av[1][i])
			i++;
		while (i >= 0)
		{
			while (av[1][i] == '\0' || av[1][i] == ' ' || av[1][i] == '\t')
				i--;
			end_word = i;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
				i--;
			start_word = i + 1;
			int in_word = start_word;
			while (start_word <= end_word)
			{
				write(1, &av[1][start_word], 1);
				start_word++;
			}
			if (in_word != 0)
				write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
}
