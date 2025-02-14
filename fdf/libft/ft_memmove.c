/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:37:54 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 08:40:59 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*ptr_src;
	char	*ptr_dst;

	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (ptr_src < ptr_dst)
		while (n--)
			ptr_dst[n] = ptr_src[n];
	else
		ft_memcpy(ptr_dst, ptr_src, n);
	return (ptr_dst);
}

/* The  memmove()  function  copies n bytes from memory area src to memory
area dest.  The memory areas may overlap: copying takes place as though
the  bytes in src are first copied into a temporary array that does not
overlap src or dest, and the bytes are then copied from  the  temporary
array to dest.*/
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