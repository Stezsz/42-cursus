#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Verifica se é seguro colocar uma rainha na posição (col, row)
// tab[i] armazena a linha da rainha na coluna i
int is_safe(int *tab, int col, int row)
{
    for(int i = 0; i < col; i++) // Verifica todas as colunas anteriores
    {
        // Conflito na mesma linha OU na diagonal
        if(tab[i] == row || abs(i - col) == abs(tab[i] - row))
            return 0; // Posição não é segura
    }
    return 1; // Posição é segura
}

// Algoritmo recursivo de backtracking para resolver N-Queens
// tab: array que armazena posição da rainha em cada coluna
// n: tamanho do tabuleiro | col: coluna atual sendo processada
void solve(int *tab, int n, int col)
{
    if(col == n) // Se colocou rainhas em todas as colunas
    {
        for(int i = 0; i < n; i++) // Imprime solução
        {
            printf("%d",tab[i]); // Linha da rainha na coluna i
            if(i < n - 1)
                printf(" "); // Espaço entre números
        }
        printf("\n");
        return ;
    }
    // Tenta colocar rainha em cada linha da coluna atual
    for(int i= 0; i < n; i++)
    {
        if(is_safe(tab , col , i)) // Se posição (col,i) é segura
        {
            tab[col] = i; // Coloca rainha na linha i da coluna col
            solve(tab, n, col + 1); // Recursão para próxima coluna
            // Backtracking automático: quando retorna, tab[col] é sobrescrito
        }
    }
}

int main(int ac , char **argv)
{
    if(ac != 2) // Precisa exatamente de um argumento (tamanho do tabuleiro)
        return 0;
    int n = atoi(argv[1]); // Converte string para inteiro
    int *tab = calloc(sizeof(int) , n); // Array para armazenar posições das rainhas
    solve(tab ,n,0); // Inicia resolução na coluna 0
    return 0;
}
