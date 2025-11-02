#include <stdio.h>
// #include <malloc.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node *parse_expr(char **s);
node *parse_factor(char **s);
node *parse_term(char **s);

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
    exit(1);
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
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

int ft_balance(char *str)
{
    int = 0;
    int open = 0;
    int close = 0;
    while (*str)
    {
        if (*str == '(')
            open++;
        else if (*str == ')')
            close++;
        str++;
    }
    if (open != close)
    {
        if (open > close)
            printf("unexpected token '('\n");
        else
            printf("unexpected token ')'\n");
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    char *s = argv[1];
    node *tree = parse_expr(&s);
    if (!tree || *s) {
        if (*s)
            unexpected(*s); // Caractere inesperado
        else
            unexpected(0);
        return (1);
    }
    if (ft_balance(argv[1]) == 1)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);
}
