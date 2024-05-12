/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:50:27 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/12 17:39:23 by vlorenzo         ###   ########.fr       */
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
		return(NULL);
	}
	return (NULL);
}

/* strchr() locates the first occurrence of c (converted to a char)
in the string pointed to by s. The termi-nating null character is
considered to be part of the string; therefore if c is `\0', the
functions locate the terminating `\0'. 

return(char *)s; converts const char *s >> char*s & equals *pos to *s
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
	chr = 	ft_strchr(str, c2); //en la definicion del puntero no hace falta poner *
	printf("test %s\n", chr); //tambien: printf("test %s\n", ft_strchr(str, c2));

	return(0);
}