/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:07:35 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	i;

	dst = malloc(ft_strlen(s)+ 1 * sizeof(char));
	i = 0;
	if (dst == NULL || s == NULL || f == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s))
	{
		dst[i] = (*f)(i, s[i]);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
/* char ft_toupper_wrapper(unsigned int i, char c)
{
    return ft_tolower(c);
}
int main()
{
char s1 [] = "ANDRES";
printf("%s",ft_strmapi(s1,ft_toupper_wrapper));
}
*/