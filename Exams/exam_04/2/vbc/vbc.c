#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Forward declaration
int parse_expression(char **s);

// Imprime erro e sai
void unexpected(char c) {
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
    exit(1);
}

// Parseia um "fator": um número ou uma expressão entre parênteses.
int parse_factor(char **s) {
    if (isdigit(**s)) {
        int val = **s - '0';
        (*s)++;
        return val;
    }
    if (**s == '(') {
        (*s)++; // Consome '('
        int result = parse_expression(s);
        if (**s != ')') {
            unexpected(**s);
        }
        (*s)++; // Consome ')'
        return result;
    }
    unexpected(**s);
    return 0; // Unreachable
}

// Parseia e avalia a expressão da esquerda para a direita.
int parse_expression(char **s) {
    int result = parse_factor(s);

    while (**s) {
        char op = **s;
        if (op == '+' || op == '*') {
            (*s)++; // Consome o operador
            int next_val = parse_factor(s);
            if (op == '+') {
                result += next_val;
            } else {
                result *= next_val;
            }
        } else if (op == ')') {
            // Fim da sub-expressão, tratado em parse_factor
            break;
        } else {
            // Caractere inválido
            unexpected(op);
        }
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }
    char *s = argv[1];
    int result = parse_expression(&s);

    // Se sobrou algum caractere que não foi processado, é um erro.
    if (*s) {
        unexpected(*s);
    }

    printf("%d\n", result);
    return 0;
}
