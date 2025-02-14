/*	Subject
	Assignment name : is_power_of_2
	Expected files : is_power_of_2.c
	Allowed functions : None
	--------------------------------------------------------------------------------
	Write a function that determines if a given number is a power of 2.

	This function returns 1 if the given number is a power of 2,
	otherwise it returns 0.

	Your function must be declared as follows :

	int is_power_of_2(unsigned int n);
	*/

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0 || n == 1)
		return (0);
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
		}
		else
			break ;
	}
	if (n == 1)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int n1 = 8;
	int n2 = 0;
	int n3 = 2;
	int n4 = 9;

	if (is_power_of_2(n1))
		printf("is power of 2\"%d\n", n1);
	else
		printf("is NOT power of 2\"%d\n", n1);

	if (is_power_of_2(n2))
		printf("is power of 2\"%d\n", n2);
	else
		printf("is NOT power of 2\"%d\n", n2);

	if (is_power_of_2(n3))
		printf("is power of 2\"%d\n", n3);
	else
		printf("is NOT power of 2\"%d\n", n3);

	if (is_power_of_2(n4))
		printf("is power of 2\"%d\n", n4);
	else
		printf("is NOT power of 2\"%d\n", n4);

	return (0);
}