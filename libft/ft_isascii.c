/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:59:32 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/15 08:09:55 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}
/* 
#include "stdio.h"
int main (void)
{
	printf("test 1 %d\n", ft_isascii(128));
	printf("test 2 %d\n", ft_isascii('0'));
	printf("test 3 %d\n", ft_isascii('a'));
	printf("test 4 %d\n", ft_isascii(52));
	
	return(0);
}

//The isascii() function tests for an ASCII character,
//which is any character between 0 and octal 0177 inclusive.

//Tambien funciona asi:
//int	ft_isascii(int i) {return (i >= 0 && i <= 127);}
 */