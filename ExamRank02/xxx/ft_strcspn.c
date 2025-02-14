#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*s)
	{
		while (reject[i] && *s != reject[i])
			i++;
		if (reject[i] != '\0')
			return (count);
		i = 0;
		count++;
		s++;
	}
	return (count);
}

/* 
#include <stdio.h>
int	main(void)
{
	char str1[] = {"Hola que ase"};
	char str2[] = {"qae"};

	printf("Length that contains none reject %zu\n", ft_strcspn(str1, str2));
} */