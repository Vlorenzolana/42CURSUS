/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:47:40 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 08:45:39 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			b;
	char			*pos;

	b = (char) c;
	i = 0;
	pos = NULL;
	while (s[i])
	{
		if (s[i] == b)
			pos = (char *) &s[i];
		i++;
	}
	if (s[i] == b)
		pos = (char *)&s[i];
	return (pos);
}

/* MAN: The strrchr() function returns a pointer to the last occurrence of  the
character c in the string s.
RETURN VALUE: The strchr() and strrchr() functions return a pointer to matched
character  or NULL if the character is not found.  The terminating null byte is
considered part of the string, so that if  c  is  specified  as'\0', functions
return a pointer to the terminator. */
/*
int main(void)
{
	int c1;
	int c2;
	int c3;
	char *chr;
	const char str[] = "Hola, Mundo!";
	
	c1 = 'o';
	c2 = 11;
	c3 = 'M';
	chr = 	ft_strrchr(str, c1);
	printf("test %s\n", chr);

	return(0);
} */