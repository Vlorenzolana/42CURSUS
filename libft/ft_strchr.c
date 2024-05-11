/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vlorenzo <vlorenzo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:50:27 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/04/12 14:57:56 by Vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return((char *)s);
		s++;
	}
	
	if (c == '\0')
	{
		return(0);
	}
	return (0);
}

/* strchr() locates the first occurrence of c (converted to a char)
in the string pointed to by s. The termi-nating null character is
considered to be part of the string; therefore if c is `\0', the
functions locate the terminating `\0'. 

	*pos = (char *)s; converts: const char *s --> char *s && equals *pos t *s
*/

#include <stdio.h>
int main(void)
{
	int c1;
	int c2;
	int c3;
	char *chr;
	const char str [] = {"Hola, Mundo!"};

	c1 = 'a';
	c2 = 'o';
	c3 = 'M';
	chr = 	ft_strchr(str, c2);
	printf("test %s\n", chr); //tambien: printf("test %s\n", ft_strchr(str, c2));

	return(0);
}