/*
Subject

Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char	*ft_strdup(char *src);
*/

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i])
		i++;

	dst = (char *)malloc(sizeof(char) *(i + 1));

	if(!dst)
		return (NULL);

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}

		dst[i] = '\0';
		return (dst);
}
/* 
int	main(int ac, char **av)
{
	char *s2;

	if (ac == 2)
	{
		printf("The original string is: %s\n", av[1]);
		s2 = ft_strdup(av[1]);
		if(!s2)
		{
			printf("Memory allocation failed");
			return (1);
		}
		printf("The copied string is: %s\n", s2);
		free(s2);
	}
	return (0);
} */