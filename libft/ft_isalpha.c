/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vlorenzo <vlorenzo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:52:39 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/04/11 12:53:45 by Vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{
	if (('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z'))
		return (1);
	return (0);
}

/* 
//tambien funcion asi:
//int	ft_isalpha(int i) 
//{return(('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z'))}

#include "stdio.h"
int main (void)
{
	printf("test 1 %d\n", ft_isalpha('0'));
	printf("test 2 %d\n", ft_isalpha('a'));
	printf("test 3 %d\n", ft_isalpha(','));
	printf("test 4 %d\n", ft_isalpha('^'));
	printf("test 5 %d\n", ft_isalpha('9'));
	return(0);
}

//The isalpha() function tests for any character for which isupper(3)
//or islower(3) is true. The value of the argument must be representable
//as an unsigned char or the value of EOF.
 */