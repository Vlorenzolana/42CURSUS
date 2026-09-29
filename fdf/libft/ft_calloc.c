/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:06:41 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/07/29 15:45:29 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	void	*dst;

	s = count * size;
	dst = malloc(s);
	if (dst == NULL)
		return (NULL);
	else
		ft_memset(dst, 0, s);
	return (dst);
}

/*  The calloc() function allocates memory for an array of  nmemb  elements
of  size bytes each and returns a pointer to the allocated memory.  The
memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
either  NULL,  or a unique pointer value that can later be successfully
passed to free(). */

/* #include <stdio.h>
int	main(void)
{
	printf("Address of p: %p\n", (void *)ft_calloc(5, 1)); // o sizeof(char) = 1
	//(void *)ptr casts the pointer to void * because %p expects a void* argument
	printf("The string es: %s\n", (char *)ft_calloc(5, 1));// o sizeof(char) = 1
	//cast(char *) because %s expects a string/char * argument, since void *,
	//we can convert to anything we need, char in this case.
	return (0);
} */