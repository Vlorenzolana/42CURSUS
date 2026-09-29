/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:25:53 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/06/21 10:38:45 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*found;

	found = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			found = (char *)s;
			return (found);
		}
		else
			s++;
	}
	return (found);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	void	*dst;
	size_t	i;

	s = count * size;
	dst = malloc(s);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < s)
	{
		*(unsigned char *)(dst + i) = (unsigned char)0;
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!storage)
		storage = ft_calloc(1, sizeof(char));
	if (!storage)
		return (NULL);
	res = ft_calloc((ft_strlen(storage) + ft_strlen(buffer) + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\0')
	{
		res[i] = storage[i];
		i++;
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\0')
		res[i++] = buffer[j++];
	res[ft_strlen(storage) + ft_strlen(buffer)] = '\0';
	free (storage);
	return (res);
}
