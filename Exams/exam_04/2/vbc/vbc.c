#include <stdio.h>
// #include <malloc.h>
#include <ctype.h>
#include <stdlib.h>

// Nó da árvore sintática para expressões matemáticas
typedef struct node {
    enum {
        ADD,   // Operação de adição
        MULTI, // Operação de multiplicação
        VAL    // Valor numérico (folha da árvore)
    }   type;
    int val;          // Valor (apenas para tipo VAL)
    struct node *l;   // Filho esquerdo
    struct node *r;   // Filho direito
}   node;

node *parse_expr(char **s);   // Parseia expressão (menor precedência: +)
node *parse_factor(char **s); // Parseia fator (maior precedência: números e parênteses)
node *parse_term(char **s);   // Parseia termo (precedência média: *)

// Cria novo nó na heap copiando estrutura fornecida
node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n; // Copia conteúdo
    return (ret);
}

// Libera árvore recursivamente (pós-ordem)
void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL) // Se não é folha, libera filhos primeiro
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n); // Libera nó atual
}

// Imprime erro para caractere inesperado e termina programa
void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpexted end of input\n");
    exit(1);
}

// Consome caractere específico se for o próximo na string
int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++; // Avança ponteiro da string
        return (1);
    }
    return (0);
}

// Espera caractere específico, senão gera erro fatal
int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s); // Termina programa com erro
    return (0);
}


// Avalia árvore sintática recursivamente
int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:   // Soma dos filhos
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI: // Multiplicação dos filhos
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:   // Retorna valor da folha
            return (tree->val);
    }
    return (0);
}

// Parseia expressão: termo + termo + termo... (associativa esquerda)
// Precedência mais baixa: + tem menor precedência que *
node *parse_expr(char **s) {
    node *left = parse_term(s); // Parseia primeiro termo
    if (!left)
        return (NULL);
    while (accept(s, '+')) { // Enquanto encontrar '+'
        node *right = parse_term(s); // Parseia próximo termo
        if (!right) {
            destroy_tree(left);
            return (NULL);
        }
        // Cria nó ADD com left e right como filhos
        node n = {ADD, 0, left, right};
        left = new_node(n); // left agora aponta para novo nó
        if (!left) {
            destroy_tree(right);
            return (NULL);
        }
    }
    return (left);
}

// Parseia fator: número isolado ou expressão entre parênteses
// Precedência mais alta: números e () são atômicos
node *parse_factor(char **s) {
    if (isdigit(**s)) { // Se é dígito (0-9)
        node n = {VAL, **s - '0', NULL, NULL}; // Converte char para int
        (*s)++; // Avança para próximo caractere
        return (new_node(n));
    }
    if (accept(s, '(')) { // Se encontra parênteses
        node *n = parse_expr(s); // Parseia expressão dentro dos parênteses
        if (!expect(s, ')')) { // Espera parênteses de fechamento
            destroy_tree(n);
            return (NULL);
        }
        return (n);
    }
    unexpected(**s); // Token não reconhecido
    return (NULL);
}

// Parseia termo: fator * fator * fator... (associativa esquerda)
// Precedência média: * tem mais precedência que + mas menos que números/parênteses
node *parse_term(char **s) {
    node *left = parse_factor(s); // Parseia primeiro fator
    if (!left)
        return (NULL);
    while (accept(s, '*')) { // Enquanto encontrar '*'
        node *right = parse_factor(s); // Parseia próximo fator
        if (!right) {
            destroy_tree(left);
            return (NULL);
        }
        // Cria nó MULTI com left e right como filhos
        node n = {MULTI, 0, left, right};
        left = new_node(n); // left agora aponta para novo nó
        if (!left) {
            destroy_tree(right);
            return (NULL);
        }
    }
    return (left);
}

int main(int argc, char **argv)
{
    if (argc != 2) // Precisa exatamente de uma expressão
        return (1);
    char *s = argv[1]; // Expressão matemática como string
    node *tree = parse_expr(&s); // Constrói árvore sintática
    if (!tree || *s) { // Se parsing falha OU sobram caracteres não processados
        if (*s)
            unexpected(*s); // Caractere inesperado
        else
            unexpected(0); // Fim de input inesperado
        return (1);
    }
    printf("%d\n", eval_tree(tree)); // Avalia e imprime resultado
    destroy_tree(tree); // Libera memória
}
