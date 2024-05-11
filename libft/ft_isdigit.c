/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vlorenzo <vlorenzo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:55:04 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/04/11 12:52:53 by Vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if ('0' <= i && i <= '9')
		return (1);
	return (0);
}

/* 
#include "stdio.h"
int main(void)
{
	printf( "Prueba a %d \n", ft_isdigit('a'));
	printf( "Prueba 0 %d \n", ft_isdigit('0'));
	printf( "Prueba 4 %d \n", ft_isdigit('4'));
	printf( "Prueba P %d \n", ft_isdigit('P'));

	return(0);
}
 */
//tambien funciona asi
//int ft isdigit(int i) { return ('0' <= i && i <= '9') };

/* 
The isdigit() function tests for a decimal digit character. 
Regardless of locale, this includes only "0" to "9".
The isnumber() function behaves similarly to isdigit(), but may
recognize additional characters, depending on the current locale
setting.
The isdigit() and isnumber() functions return zero if the character
tests false and return non-zero if the character tests true.*/ 