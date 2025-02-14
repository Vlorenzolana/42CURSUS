/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:57:07 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 08:41:23 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	void	*result;

	result = ft_memchr("12345~ª/aSdF", '5', 3);
	if (result != NULL)
		printf ("Encontrado: %c\n", *(char *)result);
	else
		printf ("Carácter no encontrado\n");
	return (0);
} */