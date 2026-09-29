/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:37:20 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/16 16:24:28 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_free_array(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}

static int	word_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*fill_word(const char *string, int len)
{
	char	*temp;
	int		i;

	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = string[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(const char *s, char c)
{
	int		len;
	int		j;
	char	**rest;

	rest = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!rest || !s)
		return (NULL);
	j = 0;
	while (*s && *s == c)
		s ++;
	while (*s)
	{
		len = 0;
		while (s[len] && s[len] != c)
			len ++;
		rest[j] = fill_word(s, len);
		if (rest[j++] == NULL)
			return (ft_free_array(rest), NULL);
		s += len;
		while (*s && *s == c)
			s ++;
	}
	rest[j] = NULL;
	return (rest);
}
