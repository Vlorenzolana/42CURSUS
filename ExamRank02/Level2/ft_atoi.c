/* Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
 */

int	ft_atoi(const char *str)
{
	int	x;
	int	sign;

	x = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		x = x * 10 + (*str - '0');
		str++;
	}
	return (x * sign);
}

/*
The atoi() function converts the initial 
portion of the string pointed to by str to
int representation. */
/* 
#include <stdio.h>
int main(void)
{
	int res1;
	int res2;
	int res3;
	int res4;
	int res5;

	char num1[] = {"1234567890"};
	char num2[] = {"-1234567890"};
	char num3[] = {"--1234567890"};
	char num4[] = {"---1234567890"};
	char num5[] = {"+1234567890"};

	res1 = ft_atoi(num1);
	printf("test 1 %d\n", res1);

	res2 = ft_atoi(num2);
	printf("test 2 %d\n", res2);

	res3 = ft_atoi(num3);
	printf("test 3 %d\n", res3);

	res4 = ft_atoi(num4);
	printf("test 4 %d\n", res4);

	res5 = ft_atoi(num5);
	printf("test 5 %d\n", res5);

	return(0);
}
 */