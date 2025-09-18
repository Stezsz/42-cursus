#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Imprime os elementos de um subconjunto separados por espaço
void print_table(int *res, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (i) printf(" "); // Espaço entre elementos (não no primeiro)
		printf("%d", res[i]);
	}
	printf("\n");
}

// Algoritmo recursivo para gerar subconjuntos com soma específica
// Para cada elemento: decide se inclui ou não no subconjunto atual
void powerset(int i, int size, int current_sum, int target, int *res, int *tab, int len)
{
	if (i == size) // Processou todos os elementos
	{
		if (current_sum == target) // Se soma do subconjunto = target
			print_table(res, len); // Imprime este subconjunto
		return;
	}
	// OPÇÃO 1: Inclui elemento tab[i] no subconjunto
	res[len] = tab[i]; // Adiciona elemento ao resultado
	powerset(i + 1, size, current_sum + tab[i], target, res, tab, len + 1);

	// OPÇÃO 2: NÃO inclui elemento tab[i] no subconjunto
	powerset(i + 1, size, current_sum, target, res, tab, len);
}

int main(int ac, char **av)
{
	if (ac < 3) // Precisa de pelo menos: programa + target + 1 número
		return 1;
	int target = atoi(av[1]); // Primeiro arg é a soma alvo
	int n = ac - 2; // Número de elementos = total args - programa - target
	int *tab = malloc(sizeof(int) * n); // Array com os números fornecidos
	if (!tab)
		return 1;
	for (int i = 0; i < n; i++) // Converte strings para inteiros
		tab[i] = atoi(av[i + 2]); // av[2] em diante são os números
	int *res = malloc(sizeof(int) * n); // Array para armazenar subconjunto atual
	if (!res)
	{
		free(tab);
		return 1;
	}
	// Inicia recursão: índice 0, soma 0, tamanho 0
	powerset(0, n, 0, target, res, tab, 0);
	free(res);
	free(tab);
	return 0;
}
