/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:06:41 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/14 13:00:18 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	b;
	void	*p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	else
		// ft_bzero(p, b);
		ft_memset(p, '1', b);
	return (p);
}

/* #include <stdio.h>
int	main(void)
{
	printf("Address of p: %p\n", (void *)ft_calloc(5, 1)); // o sizeof(char) = 1
	//(void *)ptr casts the pointer to void * because %p expects a void
		* argument
	printf("The string es: %s\n", (char *)ft_calloc(5, 1));// o sizeof(char) = 1
	//cast(char *) because %s expects a string/char * argument, since void *,
	//we can convert to anything we need, char in this case.
	return (0);
} */