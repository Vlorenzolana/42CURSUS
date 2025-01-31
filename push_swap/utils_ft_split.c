/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:44:18 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/30 07:57:10 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**tidy_arg(char *argv)
{
	char	*tmp;
	char	**tidy;

	tmp = ft_strjoin("./push_swap ", argv);
	tidy = ft_split(tmp, ' ');
	free(tmp);
	tmp = NULL;
	return (tidy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		lens1;
	int		lens2;

	if (s1 && s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2);
		s3 = (char *)malloc(1 * (lens1 + lens2 + 1));
		if (s3 == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			s3[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			s3[lens1] = s2[i];
			lens1++;
		}
		s3[lens1] = '\0';
		return (s3);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*c;

	c = (char *)malloc((sizeof(char)) * ft_strlen(s1) + 1);
	if (c == NULL)
		return (NULL);
	else
		ft_strlcpy(c, s1, (ft_strlen(s1) + 1));
	return (c);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (dstsize < 1)
		return (slen);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
