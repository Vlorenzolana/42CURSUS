/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

 */

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;
	int	i;
	int	c;

	res = 0;
	sign = 1;
	i = 0;
	if (*str == '-')
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
}
/* 
// Main program

int	main(void)
{
	printf("Result of ft_atoi_base(\"1aF\", 16): %d\n", ft_atoi_base("1aF",
			16)); // Should print 431
	printf("Result of ft_atoi_base(\"1a\", 10): %d\n", ft_atoi_base("1a",
			10));     // Should print 1
	printf("Result of ft_atoi_base(\"123\", 2): %d\n", ft_atoi_base("123",
			2));     // Should print 1 (stops at '2')
	printf("Result of ft_atoi_base(\"-1A\", 16): %d\n", ft_atoi_base("-1A",
			16));   // Should print -26

	return (0);
} */