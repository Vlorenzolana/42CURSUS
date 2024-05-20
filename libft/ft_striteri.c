/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:52:36 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/17 09:41:16 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* #include <stdio.h>
#include <stdlib.h>

void to_upper(unsigned int index, char *c)
{
	(void)index; //para usar sin usar
	 if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}
int main(void)
{
	char original_str[] = "Hola!";

	ft_striteri(original_str, to_upper);
	// Print the original and the mapped strings
    printf("Mapped string: %s\n", original_str);

    return 0;
}  */