/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:28:59 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < dstsize && dst[x] != '\0')
	{
		x++;
	}
	while ((x + y + 1) < dstsize && src[y] != '\0')
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x != dstsize)
	{
		dst[x + y] = '\0';
	}
	return (x + ft_strlen(src));
}
/*
int main(void)
{
    char dst[10] = "Hola";
    char src[] = " Mundo";
    size_t dstsize = sizeof(dst);

    ft_strlcat(dst, src, dstsize);

    printf("%s\n", dst);

    return 0;
}
*/