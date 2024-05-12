unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
	{
		i++;
	}
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
	{
		dest[i + j] = '\0';
	}
	while (src[j] != '\0')
	{
		j++;
	}
	return (i + j);
}

/* 
#include <stdio.h>
#include <string.h>

int main(void) {
    char dest[200] = "Desde que el mundo es mundo. ";
    char src[] = "Andamos sin rumbo!";
	ft_strlcat(dest, src, sizeof(dest) - strlen(dest) - 1); 
	// Calculate available space
    printf("Original string: %s\n", src);
    printf("String after ft_strlcat: %s\n", dest);
    printf("Number of characters that could be appended: %u\n", new_size);

    return (0);
}
 */