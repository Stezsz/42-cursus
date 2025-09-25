# Diferenças entre given.c e vbc.c

## given.c:
```c
#include <stdio.h>
#include <malloc.h> // change this to <stdlib.h>
#include <ctype.h>
```

## vbc.c:
```c
#include <stdio.h>
// #include <malloc.h>
#include <ctype.h>
#include <stdlib.h>
```

---

## given.c:
```c
node *n(**s);
```

## vbc.c:
```c
node *parse_expr(char **s);
node *parse_factor(char **s);
node *parse_term(char **s);
```

---

## given.c:
```c
void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}
```

## vbc.c:
```c
void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
    exit(1);
}
```

---

## given.c:
```c
int accept(char **s, char c)
{
    if (**s)
    {
        (*s)++;
        return (1);
    }
    return (0);
}
```

## vbc.c:
```c
int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}
```

---

## given.c:
```c
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
}
```

## vbc.c:
```c
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
```

---

## given.c:
```c
node    *parse_expr(char *s)
{
    //...

    if (*s)
    {
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}
```

## vbc.c adiciona estas funções:

```c
node *parse_expr(char **s) {
    node *left = parse_term(s);
    if (!left)
        return (NULL);
    while (accept(s, '+'))
    {
        node *right = parse_term(s);
        if (!right)
        {
            destroy_tree(left);
            return (NULL);
        }
        node n = {ADD, 0, left, right};
        left = new_node(n);
        if (!left)
        {
            destroy_tree(right);
            return (NULL);
        }
    }
    return (left);
}

node *parse_factor(char **s) {
    if (isdigit(**s)
    {
        node n = {VAL, **s - '0', NULL, NULL};
        (*s)++;
        return (new_node(n));
    }
    if (accept(s, '('))
    {
        node *n = parse_expr(s);
        if (!expect(s, ')'))
        {
            destroy_tree(n);
            return (NULL);
        }
        return (n);
    }
    unexpected(**s);
    return (NULL);
}

node *parse_term(char **s) {
    node *left = parse_factor(s);
    if (!left)
        return (NULL);
    while (accept(s, '*'))
    {
        node *right = parse_factor(s);
        if (!right)
        {
            destroy_tree(left);
            return (NULL);
        }
        node n = {MULTI, 0, left, right};
        left = new_node(n);
        if (!left)
        {
            destroy_tree(right);
            return (NULL);
        }
    }
    return (left);
}
```

---

## given.c:
```c
int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}
```

## vbc.c:
```c
int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    char *s = argv[1];
    node *tree = parse_expr(&s);
    if (!tree || *s) {
        if (*s)
            unexpected(*s);
        else
            unexpected(0);
        return (1);
    }
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);
}
```
