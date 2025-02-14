/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char	*ft_strcpy(char *s1, char *s2);
// man strcpy => char *strcpy(char *dest, const char *src)
*/

#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (0);
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
    s1[i] = 0;
    return(s1);
}

/* 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *src = "Hello, world!";
	char *dest;

	dest = malloc(strlen(src) + 1);
	if (!dest)
	{
		write(1, "Memory allocation failed\n", 25);
		return (1);
	}

	ft_strcpy(dest, src);

    write(1, "The copied string is:\n", 23);
	write(1, dest, strlen(dest));
	write(1, "\n", 1);

    write(1, "The original string is:\n", 25);
	write(1, dest, strlen(dest));
	write(1, "\n", 1);

	free(dest);
	return (0);
} */
