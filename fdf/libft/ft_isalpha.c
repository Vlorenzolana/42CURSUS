/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:52:39 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/17 10:21:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
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
*/
/* The isalpha() function tests for any character for which
isupper(3) or islower(3) is true. The value of the argument
must be representable as unsigned char or the value of EOF. */