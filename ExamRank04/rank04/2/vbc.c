#include <stdio.h>
#include <stdlib.h>    // MOD: on utilise <stdlib.h> pour calloc/free au lieu de <malloc.h>
#include <ctype.h>

typedef struct node {
    enum { 
        ADD, 
        MULTI,
        VAL 
    }   type;
    int           val;
    struct node   *l;
    struct node   *r;
} node;

node *new_node(node n)
{
    node *ret = calloc(1, sizeof(*ret));  // MODIFIED: sizeof(*ret) instead sizeof(n)
    if (!ret)
        return NULL;
    *ret = n;
    return ret;
}

void destroy_tree(node *n)
{
    if (!n)
        return;
    if (n->type != VAL) {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");  // MODIFIED: correct message according to the subject
}

/* MODIFIED: accept/expect remises à la signature d’origine, sans global */
int accept(char **s, char c)
{
    if (**s == c) {
        (*s)++;
        return 1;
    }
    return 0;
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return 1;
    unexpected(**s);
    return 0;
}

/* ADDED: déclarations des fonctions de parsing récursif */
static node *parse_expr_r(char **s);
static node *parse_term   (char **s);
static node *parse_factor (char **s);

/* ADDED: parsing d’un facteur (chiffre ou parenthèse) */
static node *parse_factor(char **s)
{
    if (isdigit((unsigned char)**s)) {
        node n = { .type = VAL, .val = **s - '0', .l = NULL, .r = NULL };
        (*s)++;
        return new_node(n);
    }
    if (accept(s, '(')) {
        node *e = parse_expr_r(s);
        if (!e)
            return NULL;
        if (!expect(s, ')')) {          // MOD: vérification de la parenthèse fermante
            destroy_tree(e);
            return NULL;
        }
        return e;
    }
    unexpected(**s);
    return NULL;
}

/* ADDED: parsing d’un terme (multiplications) */
static node *parse_term(char **s)
{
    node *left = parse_factor(s);
    if (!left)
        return NULL;
    while (accept(s, '*')) {
        node *right = parse_factor(s);
        if (!right) {
            destroy_tree(left);
            return NULL;
        }
        node n = { .type = MULTI, .l = left, .r = right };
        left = new_node(n);
        if (!left)
            return NULL;
    }
    return left;
}

/* ADDED: parsing d’une expression (additions) */
/* THIS FUNCTION IS A COPY PASTE OF PARSE_TERM, YOU JUST HAVE TO REPLACE '*' by '+' !!!!!*/
static node *parse_expr_r(char **s)
{
    node *left = parse_term(s);
    if (!left)
        return NULL;
    while (accept(s, '+')) {
        node *right = parse_term(s);
        if (!right) {
            destroy_tree(left);
            return NULL;
        }
        node n = { .type = ADD, .l = left, .r = right };
        left = new_node(n);
        if (!left)
            return NULL;
    }
    return left;
}

/* MODIFIED: parse_expr initialise un pointeur local et vérifie la fin de la chaîne */
node *parse_expr(char *s)
{
    char *p = s;
    node *ret = parse_expr_r(&p);
    if (!ret)
        return NULL;
    if (*p) {                          
        unexpected(*p);
        destroy_tree(ret);
        return NULL;
    }
    return ret;
}

int eval_tree(node *tree)
{
    switch (tree->type) {
        case ADD:   return eval_tree(tree->l) + eval_tree(tree->r);
        case MULTI: return eval_tree(tree->l) * eval_tree(tree->r);
        case VAL:   return tree->val;
    }
    return 0;  // should no happen, but who know's ?
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return 1;
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return 0;
}
