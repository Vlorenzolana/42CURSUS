/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:41:54 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (src[y] != '\0')
	{
		y++;
	}
	while (src[x] && x + 1 < size)
	{
		dst[x] = src[x];
		x++;
	}
	if (size != '\0')
	{
		dst[x] = '\0';
	}
	return (y);
}
/* 
int main (void)
{
	char src[] = "prueba copiar str";
	char dst[10];
	size_t size = sizeof(dst);
	
	ft_strlcpy(dst, src, size);
	printf("%s\n", dst);
}
 */