/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:06:26 by dalabrad          #+#    #+#             */
/*   Updated: 2025/03/06 12:16:20 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			len_dest;
	size_t			len_src;
	unsigned int	i;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size == 0)
		return (len_src);
	i = 0;
	while (src[i] != '\0' && (i + len_dest) < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (size < len_dest + 1)
		len_src += size;
	else
		len_src += len_dest;
	dest[len_dest + i] = '\0';
	return (len_src);
}
