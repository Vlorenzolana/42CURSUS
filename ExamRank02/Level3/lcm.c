/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

unsigned int	lcm(unsigned int a, unsigned int b);

// Function that calculates the least common multiple (LCM) of two positive integers

// Example lmc of 14, 20 is 140
*/

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		else
			n++;
	}
}

/* 
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	number;

	if (ac == 3)
	{
		number = lcm(atoi(av[1]), atoi(av[2]));
		printf("%u\n", number);
	}
	return (0);
} */
