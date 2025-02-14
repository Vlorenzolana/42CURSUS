/*
Write the following function:

int	*ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int i = 0;
	int len;
	int *r;

	len = abs(start - end) + 1;
	r = (int *)malloc(sizeof(int) * len);
	
	if(!r)
		return(0);

	if(start > end)
	{
		while(i < len)
		{
			r[i] = start;
			start--;
			i++;
		}
	}
	else if(start < end)
	{
		while(i < len)
		{
			r[i] = start;
                        start++;
                        i++;
		}
	}
	return(r);
}

#include <stdio.h>
int main(void)
{
	int *range;
	int start = 3;
	int end = 0;
	int i = 0;
	int len = abs(start - end) + 1;
	range = ft_range(start, end);
       	
	while( i < len)
		printf("%d\n", range[i++]);
	return(0);
}

