#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_table(int *res, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (i) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
}

void powerset(int i, int size, int current_sum, int target, int *res, int *tab, int len)
{
	if (i == size)
	{
		if (current_sum == target)
			print_table(res, len);
		return;
	}
	res[len] = tab[i];
	powerset(i + 1, size, current_sum + tab[i], target, res, tab, len + 1);
	powerset(i + 1, size, current_sum, target, res, tab, len);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	int target = atoi(av[1]);
	int n = ac - 2;
	int *tab = malloc(sizeof(int) * n);
	if (!tab)
		return 1;
	for (int i = 0; i < n; i++)
		tab[i] = atoi(av[i + 2]);
	int *res = malloc(sizeof(int) * n);
	if (!res)
	{
		free(tab);
		return 1;
	}
	powerset(0, n, 0, target, res, tab, 0);
	free(res);
	free(tab);
	return 0;
}
