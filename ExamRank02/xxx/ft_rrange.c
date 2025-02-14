/*
Assignment name : ft_rrange 
Expected files : ft_rrange.c 
Allowed functions : malloc
--------------------------------------------------------------------------------

Write the following function : int *ft_rrange(int start, int end);

It must allocate(with malloc()) an array of integers,
	fill it with consecutive values that begin at end and end at start(Including start and end !),
	then return a pointer to the first value of the array.

	Examples :

	-With(1, 3) you will return an array containing 3,
	2 and 1 - With(-1, 2) you will return an array containing 2, 1, 0 and -1.
		- With(0, 0) you will return an array containing 0. - With(0,
		-3) you will return an array containing - 3, -2, -1 and 0.
*/

#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*rrange;
	int	len;
	int	i;

	i = 0;
	len = abs(start - end) + 1;
	rrange = (int *)malloc((sizeof(int) * len));
	while (i < len)
	{
		if (start > end)
		{
			rrange[i++] = end;
			end++;
		}
		else
		{
			rrange[i++] = end;
			end--;
		}
	}
	return (rrange);
}

int	main(void)
{
	int a;
	int b;
	int i;
	int len;
	int *str;

	a = -10;
	b = 3;
	len = abs(a - b) + 1;
	i = 0;

	printf("Los valores start\"%d\" y end\"%d\":\n", a, b);
	str = ft_rrange(a, b);
	printf("La cadena rrange es:\n");
	while (i < len) // while(str[i] NO porque no termina en 0)
		printf("%d ", str[i++]);
	printf("\n");
	// free(str);
	return (0);
}