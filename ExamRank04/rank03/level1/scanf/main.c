#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int ft_scanf(const char *, ... );

int main(void)
{
    int x;
    char str[100];
    char c;

    // Leer: número, espacio, string, espacio, carácter
    int converted = ft_scanf("%d %s %c", &x, str, &c);
    
    printf("Convertidos: %d\n", converted);
    printf("Número: %d, String: %s, Carácter: %c\n", x, str, c);
    
    return 0;
}
