/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:39:11 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/13 16:16:22 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/* The strlcpy() function copies up to size - 1 characters from
the NUL-terminated string src to dst, NUL-terminating the result.
The strlcpy() functions return the total length of the string
they tried to create. For strlcpy() that means the length of src. */

/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*d;
	int		i;

	d = (char *)malloc(20 * 1);
	if (d == NULL)
	{
		write(1, "Memory allocation failed\n", 26);
		return (0);
	}
	i = 0;
	while (i < 19)
	{
		d[i] = 'A';
		i++;
	}
	printf ("String original: %s\n", d);
	printf ("Valor retornado: %zu\n", ft_strlcpy(d, "123456789", 3));
	printf ("String final: %s\n", d);
	free (d);
	return (0);
} */