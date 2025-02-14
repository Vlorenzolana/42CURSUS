/*
	Assignment name : pgcd
	Expected files : pgcd.c
	Allowed functions : printf, atoi, malloc, free
	--------------------------------------------------------------------------------

	Write a program that takes two strings representing two strictly positive
	integers that fit in an int. Display their highest common denominator followed
	by a newline(It's always a strictly positive integer)
	If the number of parameters is not 2, display a newline.
	$> ./pgcd 42 10 | cat -e
	2$
	$> ./pgcd 42 12 | cat -e
	6$
	$> ./pgcd 14 77 | cat -e
	7$
	$> ./pgcd 17 3 | cat -e
	1$
	$> ./pgcd | cat -e
	$
*/

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	temp;

	int a; // 42
	int b; // 12
	if (ac != 3)
		return(printf("\n"));

	a = atoi(av[1]);
	b = atoi(av[2]);

	if (a == 0 && b == 0)
		printf("0");
	while (b > 0)
	{
		temp = b;  // 12 // 2 // 6
		b = a % b; // 2  // 6 // 2
		a = temp;  // 12 // 2 // 6
	}
	printf("%d\n", a); // 6
}
