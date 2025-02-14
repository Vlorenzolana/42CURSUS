int	ft_atoi(const char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 1;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;

	while (*str == '+' || *str == '-')
	{
		if (*str < 0)
			sign *= -1;
        str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
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
	char num5[] = {"+1234567890htr"};

    res1 = ft_atoi(num1);
    printf("Result1 %d\n", res1);
    
    res2 = ft_atoi(num2);
    printf("Result1 %d\n", res2);

    res3 = ft_atoi(num3);
    printf("Result1 %d\n", res3);

    res4 = ft_atoi(num4);
    printf("Result1 %d\n", res4);

    res5 = ft_atoi(num1);
    printf("Result1 %d\n", res5);
} */