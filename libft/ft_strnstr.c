/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:08:13 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/14 13:00:03 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		while (str[i + j] == needle[j] && str[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)str + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

/* #include <stdio.h>
int	main(void)
{
	printf ("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 30));
	return (0);
} */