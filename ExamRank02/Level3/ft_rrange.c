#include <stdlib.h>

int *ft_range(int start, int end)
{
	int i = 0;
	int len = abs((end - start)) + 1;
	int *res = (int *)malloc(sizeof(int) * len);
	
	while (i < len)
	{
		if (end < start)
		{
			res[i] = end;
			end++;
			i++;
		}
		else
		{
			res[i] = end;
			end--;
			i++;
		}
	}
        return (res);
}
/*
//
//Main function
#include <limits.h> // limits
#include <math.h> // abs
#include <stdio.h> // Printf
#include <stdlib.h> // Malloc & NULL

int	main(void)
{
	int	*range;
	int	start;
	int	end;
	int	i;
	int	step;
	int	n;
	int length;
	
    // Test 1: Start at INT_MIN and end at INT_MIN + 5
	start = INT_MIN;
	end = INT_MIN + 5;
	range = ft_range(start, end);
	if (range)
	{
		length = end - start + 1;
		printf("Range from %d to %d:\n", start, end);
		for (i = 0; i < length; i++)
		{
			printf("%d ", range[i]);
		}
		printf("\n");
		free(range);
	}
	// Test 2: Start at INT_MAX - 5 and end at INT_MAX
	start = INT_MAX - 5;
	end = INT_MAX;
	range = ft_range(start, end);
	if (range)
	{
		length = end - start + 1;
		printf("Range from %d to %d:\n", start, end);
		for (i = 0; i < length; i++)
		{
			printf("%d ", range[i]);
		}
		printf("\n");
		free(range);
	}
	// Test 3: Start at -5 and end at 5
	start = -5;
	end = 5;
	range = ft_range(start, end);
	if (range)
	{
		length = end - start + 1;
		printf("Range from %d to %d:\n", start, end);
		for (i = 0; i < length; i++)
		{
			printf("%d ", range[i]);
		}
		printf("\n");
		free(range);
	}
	// Test 4: Start at 5 and end at 5
	start = 5;
	end = 5;
	range = ft_range(start, end);
	if (range)
	{
		length = end - start + 1;
		printf("Range from %d to %d:\n", start, end);
		for (i = 0; i < length; i++)
		{
			printf("%d ", range[i]);
		}
		printf("\n");
		free(range);
	}
	return (0);
} */