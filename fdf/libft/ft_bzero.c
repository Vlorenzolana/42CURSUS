/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:08:13 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/07/29 15:38:11 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (0 < n)
	{
		*p = 0;
		p++;
		n--;
	}
}

/* int	main(void)
{
	char	*test_str;

	test_str = (char *)malloc(26 * sizeof(char));
	ft_strlcpy(test_str, "Abracadabra pata de cabra!", 27);
	printf ("test_str inicial: %s\n", test_str);
	ft_bzero(test_str, 10);
	printf ("test_str final: %s\n", test_str);
	free(test_str);
	return (0);
} */

/* ft_bzero toma un bloque de memoria especificado por s y n, y lo
inicializa estableciendo cada uno de sus bytes a cero. 
(Para pruebas compilar con ft_strcpy.c y ft_strlen.c) */