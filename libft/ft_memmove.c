/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:37:54 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/14 16:33:24 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	len;

	len = 0;
	if (s2 < s1)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)s1)[len] = ((unsigned char *)s2)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)s1)[len] = ((unsigned char *)s2)[len];
			len++;
		}
	}
	return (s1);
} */

/* The  memmove()  function  copies n bytes from memory area src to memory
area dest.  The memory areas may overlap: copying takes place as though
the  bytes in src are first copied into a temporary array that does not
overlap src or dest, and the bytes are then copied from  the  temporary
array to dest.*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);

	i = 0;

	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}

/* int	main(void)
{
	char	*test_dst;

	test_dst = malloc(20 * sizeof(char));
	ft_memcpy(test_dst, "QWERTYUIOP", 6);
	printf ("string copiado: %s\n", (char *)test_dst);
	free (test_dst);
	return (0);
} */

/* ft_memcpy copia n bytes de datos desde la dirección de memoria
especificada por src  a la dirección de memoria especificada por dst.
La función garantiza la copia de datos de forma directa,
byte por byte, y devuelve dst como puntero al bloque de memoria
de destino. */