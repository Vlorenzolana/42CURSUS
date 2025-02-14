/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5,
	it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
[...]
14
fizzbuzz
[...]
98
fizz
buzz
$> */

#include <unistd.h>

void	put_nbr(int n)
{
	char	digit;

	if (n >= 10)
		put_nbr(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
}

int	main(void)
{
	int i;

	i = 0;

	while (i < 100)
	{
		i++;

		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else
		{
			put_nbr(i);
		}
		write(1, "\n", 1);
	}
	return (0);
}