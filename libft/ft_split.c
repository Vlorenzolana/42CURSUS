/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:25:51 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/16 17:43:03 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **string)
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
			return (ft_free(rest), NULL);
		s += len;
		while (*s && *s == c)
			s ++;
	}
	rest[j] = NULL;
	return (rest);
}
/* 
#include <stdio.h>
int main()
{
	int i = 0;
	char **arr = ft_split("hola como estas", ' ');
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);	
} */