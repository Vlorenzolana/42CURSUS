/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:50:27 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/07/29 15:43:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*mark;

	ch = (char)c;
	mark = NULL;
	while (*s)
	{
		if (*s == ch)
		{
			mark = (char *)s;
			return (mark);
		}
		else
			s++;
	}
	if (ch == '\0')
	{
		mark = (char *)s;
		return (mark);
	}
	return (mark);
}

/* ft_strchr busca un carácter c en la cadena s y devuelve un puntero
a su primera ocurrencia si se encuentra.
Si c no está en s, la función devuelve NULL. */