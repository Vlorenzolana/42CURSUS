/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:42:58 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	if (dst > src)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (d);
}
/* 
int main()
{
	char src[] = "Hola amigo";
	char dst[20];

	printf("Antes: %s\n", dst);

	ft_memmove(dst, src, sizeof(src));

	printf("Despues: %s\n", dst);

	return(0);

} */