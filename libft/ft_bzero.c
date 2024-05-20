/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:08:13 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 17:04:48 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (0 < n)
	{
		*p = 0;
		p++;
		n--;
	}
}

/* The bzero() function writes n zeroed bytes to the string s. If n is zero,
bzero() does nothing. */
/* #include <stdio.h>
int	main(void)
{
	char str[6] = "Hello!";

	printf("Before ft_bzero: %s\n", str);
	ft_bzero(str, sizeof(str));
	printf("After ft_bzero: %s\n", str);

	return (0);
} */