/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:59:32 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/15 08:09:55 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

#include "stdio.h"
int main (int argc, char **argv)
{
	int		i;
	char	c;
	
 	if (argc != 2)
	{
		printf("Error en el num de argumentos");
		return (0);
	}
	c = argv[1][3];
	i = ft_isascii(c);
	if (i == 0)
		printf("No es un caracter ASCII return (%i)", i);
	else
		printf("Si es un caracter ASCII return (%i)", i);
	return(0);
}

//The isascii() function tests for an ASCII character,
//which is any character between 0 and octal 0177 inclusive.

//Tambien funciona asi:
//int	ft_isascii(int i) {return (i >= 0 && i <= 127);}
