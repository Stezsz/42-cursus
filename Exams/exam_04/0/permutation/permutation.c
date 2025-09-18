#include <unistd.h>
#include <stdlib.h>

// Ordena a string em ordem alfabética usando bubble sort
// Necessário para garantir que permutações saiam em ordem lexicográfica
void sorted(char *str){
    char tmp;
    for(int i = 0; str[i]; i++){
        for(int j = i+1; str[j]; j++){
            if(str[i] > str[j]){ // Se char atual > próximo
                tmp = str[i];    // Troca posições
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}

// Algoritmo recursivo de backtracking para gerar todas as permutações
// str: string original ordenada | result: permutação sendo construída
// used: marca quais caracteres já foram usados | dep: profundidade atual | len: tamanho total
void perm(char *str , char *result , int *used, int dep, int len)
{
    if (dep == len) // Se construiu permutação completa
    {
        for(int i = 0; i < len; i++) // Imprime permutação
        {
            write(1, &result[i], 1);
        }
        write(1,"\n",1);
        return;
    }
    // Tenta cada caractere não usado na posição atual
    for (int i = 0; i < len; i++)
    {
        if (used[i])  // Se já foi usado, pula
            continue;
        used[i] = 1; // Marca como usado
        result[dep] = str[i]; // Coloca na posição atual
        perm(str, result , used , dep + 1 , len); // Recursão para próxima posição
        used[i] = 0; // Backtrack: desmarca para tentar outras combinações
    }
}

int main(int argc, char **argv) {
    if (argc != 2) // Precisa exatamente de uma string
        return 1;

    int i = 0;
    while (argv[1][i]) // Calcula tamanho da string
        i++;
    int len = i;
    char *result = malloc(len + 1); // Array para construir permutações
    int *used = calloc(len, sizeof(int)); // Array para marcar chars usados (iniciado com 0)
    sorted(argv[1]); // Ordena string para garantir ordem lexicográfica
    perm(argv[1], result, used, 0, len); // Inicia geração de permutações
    free(result);
    free(used);
}
