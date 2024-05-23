/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:33:02 by otboumeh          #+#    #+#             */
/*   Updated: 2024/05/04 17:02:12 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*DESCRIPTION:
print_char is the fonction that will be responsable to print every possiblity in our code.
---------------------------------------------------------------------------*/
int	print_char(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}
/*DESCRIPTION:
putstr is the same as the one of LIBFT the onlt difference is to print (null) when our string is NULL
---------------------------------------------------------------------------*/
int	putstr(char *str, int count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		count = count + 6;
		return (count);
	}
	while (str[i])
	{
		count = print_char(str[i], count);
		i++;
	}
	return (count);
}

/*DESCRIPTION:
Write only works with chars, not with ints.
As a consequence, we've to chop numbers into making them <10,
so that we can write them as chars by ASCII table conversion (+48)
---------------------------------------------------------------------------*/

int	putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		count = print_char('-', count);
		count = putstr("2147483648", count);
		return (count);
	}
	else if (n < 0)
	{
		count = print_char('-', count);
		n = -n;
		count = putnbr(n, count);
	}
	else if (n > 9)
	{
		count = putnbr(n / 10, count);
		count = putnbr(n % 10, count);
	}
	else
		count = print_char(n + 48, count);
	return (count);
}

/*DESCRIPTION:
putunbr works in the same way putnbr does. The one difference is that 
putnbr does NOT have to manage negative numbers as it gets unsigned ints as
parameters. Which means, the negative numbers' management is no needed.
*In order to understand this, check what an unsigned int is and how does it work.
---------------------------------------------------------------------------*/

int	putnbr_pos(unsigned int n, int count)
{
	if (n == 2147483647)
	{
		count = print_char('2', count);
		count = putnbr(147483647, count);
	}
	else if (n > 9)
	{
		count = putnbr(n / 10, count);
		count = putnbr(n % 10, count);
	}
	else
		count = print_char(n + 48, count);
	return (count);
}
