#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*range;

	len = abs(start - end) + 1;
	range = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		if (start > end)
		{
			range[i] = start;
			start--;
			i++;
		}
		else
			range[i] = start;
		start++;
		i++;
	}
	return (range);
}
/* #include <stdio.h>
int	main(void)
{
	int a;
	int b;
	int *str;
	int len;
	int i;

    a = 0;
    b = 3;

    i = 0;
    len = abs(a - b) + 1;

	str = ft_range(a, b);
	while (i < len)
		printf("%d ", str[i++]);
    printf("\n");
	free(str);
	return (0);
} */