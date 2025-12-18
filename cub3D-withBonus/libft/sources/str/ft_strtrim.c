/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:49:37 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	i = ft_strlen(s1);
	while (ft_strrchr(set, s1[i]) && i)
	{
		i--;
	}
	return (ft_substr(s1, 0, i + 1));
}

/* int main()
{
	char str[] = "Hola como estas Hola";
	char brd[] = "Hola";

	printf("%s\n", ft_strtrim(str, brd));
} */