/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vlorenzo <vlorenzo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:05:53 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/04/12 14:35:48 by Vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
#include "stdio.h"
int main(void)
{
	size_t	kk;
	char s[] = {"hola, mundo!"};
	kk = ft_strlen(s); //recupera el return (en este caso (i))
	printf("test 1 %zu", kk);
	return(0);
}
//The strnlen() function attempts to compute the length of str, but never
//scans beyond the first maxlen bytes of s. */