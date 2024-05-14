/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:07:15 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/13 10:09:11 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}

/* The memset() function writes len bytes of value c (converted to an unsigned
char) to the string b. The memset() function returns its first argument. */
/* 
#include <stdio.h>
int main()
{
	char str[20];
	int c;
	size_t len;
	size_t i;

	len = sizeof(str);
	c = 'A';
	i = 0;

	// Initialize str with random values
	while (i < len)
	{
		str[i] = '0' + (i % 10);
		i++;
	}

	printf("Before ft_memset: %s\n", str);
	ft_memset(str, c, len);
	printf("After ft_memset: %s\n", str);

	return 0;
} */