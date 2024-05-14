/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:40:38 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/13 16:45:00 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (slen);
	if (dstsize <= dlen)
		return (slen + dstsize);
	else
		slen = slen + dlen;
	while (src[i] != '\0' && dlen < dstsize - 1 && dest != src)
	{
		dest[dlen] = src[i];
		i++;
		dlen++;
	}
	dest[dlen] = '\0';
	return (slen);
}

/* #include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	*test_d;
	int		i;

	test_d = (char *)malloc(20 * 1);
	if (test_d == NULL)
	{
		write(1, "Memory allocation failed\n", 26);
		return (0);
	}
	i = 0;
	while (i < 5)
	{
		test_d[i] = (char)i + '0';
		i++;
	}
	printf ("String original: %s\n", test_d);
	printf ("Valor retornado: %zu\n", ft_strlcat(test_d, "ASDFGH", 7));
	printf ("String final: %s\n", test_d);
	free (test_d);
	return (0);
} */