/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:29:56 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		x;

	i = 0;
	x = 0;
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (dst == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		dst[i] = s2[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (dst);
}

/* int main()
{
	//char p1[] = "Hola";
	char p2[] = " Mundo";

	printf("%s\n", ft_strjoin(NULL, p2));
	return (0);
} */