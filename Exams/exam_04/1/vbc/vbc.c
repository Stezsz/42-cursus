#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// Forward declarations
node *parse_expr(char **s);
node *parse_term(char **s);
node *parse_factor(char **s);

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

// Parse a factor: number or (expression)
node *parse_factor(char **s)
{
    node *result;
    
    if (isdigit(**s))
    {
        // Parse a number
        int val = 0;
        while (isdigit(**s))
        {
            val = val * 10 + (**s - '0');
            (*s)++;
        }
        result = new_node((node){.type = VAL, .val = val});
        return result;
    }
    else if (**s == '(')
    {
        // Parse parenthesized expression
        (*s)++; // consume '('
        result = parse_expr(s);
        if (!result)
            return NULL;
        if (!expect(s, ')'))
        {
            destroy_tree(result);
            return NULL;
        }
        return result;
    }
    else
    {
        unexpected(**s);
        return NULL;
    }
}

// Parse a term: factor * factor * ...
node *parse_term(char **s)
{
    node *left = parse_factor(s);
    if (!left)
        return NULL;
    
    while (**s == '*')
    {
        (*s)++; // consume '*'
        node *right = parse_factor(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }
        
        node *mult_node = new_node((node){.type = MULTI, .l = left, .r = right});
        if (!mult_node)
        {
            destroy_tree(left);
            destroy_tree(right);
            return NULL;
        }
        left = mult_node;
    }
    
    return left;
}

// Parse an expression: term + term + ...
node *parse_expr(char **s)
{
    node *left = parse_term(s);
    if (!left)
        return NULL;
    
    while (**s == '+')
    {
        (*s)++; // consume '+'
        node *right = parse_term(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }
        
        node *add_node = new_node((node){.type = ADD, .l = left, .r = right});
        if (!add_node)
        {
            destroy_tree(left);
            destroy_tree(right);
            return NULL;
        }
        left = add_node;
    }
    
    return left;
}

node    *parse_expression(char *s)
{
    char *ptr = s;
    node *ret = parse_expr(&ptr);
    
    if (!ret)
        return NULL;
    
    if (*ptr) 
    {
        unexpected(*ptr);
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    if (!tree)
        return 0;
    
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
        default:
            return 0;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expression(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);
}