/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:08:13 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/14 17:05:12 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*  The bzero() function writes n zeroed bytes to the string s. If n is zero,
bzero() does nothing.*/

/* #include <stdio.h>
int	main(void)
{
	char str[20] = "Hello, world!";
	size_t n = 5;

	printf("Before ft_bzero: %s\n", str);
	ft_bzero(str, n);
	printf("After ft_bzero: %s\n", str);

	return (0);
} */