/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vlorenzo <vlorenzo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:47:40 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/04/20 12:31:18 by Vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *pos;

	pos = NULL;
	while ( *s != '\0' )
	{
		if (c == '\0')
			return (0);
	}
	return (0);
}

/* #include <stdio.h>
int main(void)
{
	int c1;
	int c2;
	int c3;
	char *chr;
	const char str [] = {"Hola, Mundo!"};

	c1 = 'a';
	c2 = 111;
	c3 = 'M';
	chr = 	ft_strrchr(str, c2);
	printf("test %s\n", chr); //tambien: printf("test %s\n", ft_strchr(str, c2));

	return(0);
} */