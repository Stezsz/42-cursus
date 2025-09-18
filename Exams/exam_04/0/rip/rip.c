// Remove o mínimo de parênteses inválidos para imprimir todas as versões balanceadas
// Estratégia: calcula quantos precisam ser removidos e faz backtracking removendo
// parênteses um a um até atingir esse número, imprimindo combinações válidas.
#include <unistd.h>
#include <stdio.h>

// Calcula quantos parênteses precisam ser removidos para balancear a string
int	ft_balance(char *str)
{
	int closed = 0;
	int opened = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == '(')
			opened++;
		else if (str[i] == ')')
		{
			if (opened > 0)
				opened--;      // Casa com um '(' aberto
			else
				closed++;      // Excesso de ')'
		}
		i++;
	}
	return closed + opened; // Total mínimo de remoções necessárias
}

// Backtracking: tenta remover parênteses até atingir o número mínimo
// changes = quantos já removemos; balance = total necessário
void	rip(char *str, int changes, int pos, int balance)
{
	int i;
	if (balance == changes && !ft_balance(str)) // Se removemos o mínimo e está balanceada
	{
		puts(str);
		return ;
	}
	i = pos;
	while(str[i])
	{
		if (str[i] == ')' || str[i] == '(')
		{
			char c = str[i];
			str[i] = ' ';                // "Remove" temporariamente
			rip(str, changes + 1, i + 1, balance);
			str[i] = c;                  // Restaura (backtrack)
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int balance = ft_balance(av[1]);
	rip(av[1], 0, 0, balance);
	return 0;
}
