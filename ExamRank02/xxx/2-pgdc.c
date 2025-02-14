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

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char ** av)
{
	int n;
	int a;
	int b;

	if(ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
	
		if(a > b)
		{
			n = b;
			while( n >= 1)
			{
				if(a % n == 0 && b % n == 0)
					return(printf("%d\n", n));
				n--;
			}
		}

		if(b > a)
                {
                        n = a;
                        while( n >= 1)
                        {
                                if(a % n == 0 && b % n == 0)
                                        return(printf("%d\n", n));
                                n--;
                        }
                }

		if(a == b)
			return(printf("%d\n", a));

	}
	printf("\n");
	return(0);
}
