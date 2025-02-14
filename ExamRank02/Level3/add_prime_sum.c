/* 	Assignment name : add_prime_sum
	Expected files : add_prime_sum.c
	Allowed functions : write, exit
	--------------------------------------------------------------------------------

	Write a program that takes a positive integer as argument and displays
	the sum of all prime numbers inferior or equal to it followed by a newline.

	If the number of arguments is not 1,
	or the argument is not a positive number,
	just display 0 followed by a newline.

	Yes, the examples are right.

	Examples :

		$ > ./ add_prime_sum 5 10
		$ >./ add_prime_sum 7 |cat - e
		17
		$
		$ >./ add_prime_sum | cat - e
		0
		$
		$ >
		*/

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / 2))
	{
		if (!(nb % i))
			return (0);
		else
			i += 1;
	}
	return (1);
}