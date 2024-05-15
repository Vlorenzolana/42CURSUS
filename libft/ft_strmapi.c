/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:39:42 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/15 13:33:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fstr;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	fstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (fstr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
/*ft_strmapi applies the function (f) to each character of the input string (s) and returns a new string (fstr) containing the characters of the input string (s).
input string (s) and returns a new string (fstr) containing the transformed characters.
transformed characters.*/

char to_upper(unsigned int index, char c)
{
	(void)index; //para usar sin usar
	 if (c >= 'a' && c <= 'z')
		c = c - 32;
	return(c);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *original_str;
	char *mapped;

	original_str = "Hola!";
	mapped = ft_strmapi(original_str, to_upper);
	// Print the original and the mapped strings
    printf("Original string: %s\n", original_str);
    printf("Mapped string: %s\n", mapped);

    // Free the allocated memory for the mapped string
    free(mapped);

    return 0;
} */