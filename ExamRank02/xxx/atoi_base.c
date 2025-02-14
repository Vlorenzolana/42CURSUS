#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{

    int i;
    int c;
    int sign;
    int res;

	res = 0;
	sign = 1;
	i = 0;

	if ( *str == '-')
	{
		sign = -1;
		str++;
	}

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			c = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			c = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			c = str[i] - 'A' + 10;
		else
			break ;
		res = res * str_base + c;
		i++;
	}
	return (res * sign);
}/* 
int main(void)
{
	printf("Result of ft_atoi_base(\"1aF\", 16): %d\n", ft_atoi_base("1aF", 16));
	printf("Result of ft_atoi_base(\"123\", 2): %d\n", ft_atoi_base("123", 2));
	printf("Result of ft_atoi_base(\"1a\", 10): %d\n", ft_atoi_base("1a", 10));
	printf("Result of ft_atoi_base(\"-1A\", 16): %d\n", ft_atoi_base("-1A", 16));
} */