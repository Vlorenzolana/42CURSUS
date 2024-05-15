/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:52:36 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/15 13:34:18 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int i;
    
    i = 0;
    if (s == NULL)
        return; //porque es void
    /* looping over the whole original string */
    while (s[i])
    {
        /* apply the function f to the character at index i
         * passing i and the address to s[i] as parameter to f
         * f will update the original string directly
         */
        (*f)(i, &s[i]);
        i++;
    }
}

void to_upper(unsigned int index, char *c)
{
	(void)index; //para usar sin usar
	 if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char original_str[] = "Hola!";

	ft_striteri(original_str, to_upper);
	// Print the original and the mapped strings
    printf("Mapped string: %s\n", original_str);

    return 0;
} 