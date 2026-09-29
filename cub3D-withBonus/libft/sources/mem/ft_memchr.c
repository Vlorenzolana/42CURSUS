/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:28:10 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	x;
	size_t			i;

	ptr = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr == x)
		{
			return ((void *)ptr);
		}
		ptr ++;
		i++;
	}
	return (NULL);
}

/* int main()
{
	char str[] = "Hola Mundo!";
	char *result = ft_memchr(str, ' ', sizeof(str));

	if (result != NULL)
	{
	printf("si %ld\n", (long int)(result - str));
	}
	else
	{
	printf("no\n");
	}

} */