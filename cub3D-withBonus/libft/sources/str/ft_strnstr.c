/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:01:53 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (needle[0] == 0)
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i < len)
	{
		while (haystack[i + x] == needle[x] && haystack[i + x] && i + x < len)
		{
			x++;
		}
		if (needle[x] == 0)
		{
			return ((char *)haystack + i);
		}
		i++;
		x = 0;
	}
	return (0);
}
/* 
int main()
{
	char z[] = "cola como estas";
	char x[] = "com";

	printf("%s\n", ft_strnstr(z, x, 50));
} */