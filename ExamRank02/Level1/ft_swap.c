/* 
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b); 
*/

void ft_swap(int *a, int *b)
{
    int temp;

    temp  = *a;

    *a = *b;
    *b = temp;
}
/* 
#include <stdio.h>

int main (void)
{
    int n1;
    int n2;

    n1 = 0;
    n2 = 1;

    printf("Lo que era \"%d\" y \"%d\"\n", n1, n2 );
    ft_swap(&n1, &n2);
    printf("Ahora es \"%d\" y \"%d\"\n", n1, n2 );
    return(0);
} */