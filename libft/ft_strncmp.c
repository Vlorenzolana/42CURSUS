/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:55:20 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/16 08:55:52 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/* The strcmp() and strncmp() functions return an integer less than, equal to,
	or
greater than zero if s1 (or the first n bytes thereof) is found, respectively,
to be less than, to match, or be greater than s2. */

/* #include <stdio.h>
int	main(void)
{
	printf ("Diferencia: %d.\n", ft_strncmp ("123456788", "123456789", 9));
	return (0);
} */