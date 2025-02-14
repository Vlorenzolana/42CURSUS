/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:05:32 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/28 11:06:17 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gnl_calloc(size_t count, size_t size)
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

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	char	*mark;

	mark = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			mark = (char *)s;
			return (mark);
		}
		else
			s++;
	}
	return (mark);
}

char	*ft_gnl_strjoin(char *storage, char *buffer)
{
	char *s3;
	size_t i;
	size_t j;

	if (!storage)
		storage = ft_gnl_calloc(1, sizeof(char));
	if (!storage)
		return (NULL);
	s3 = ft_gnl_calloc((ft_gnl_strlen(storage) + ft_gnl_strlen(buffer) + 1),
			sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\0')
	{
		s3[i] = storage[i];
		i++;
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\0')
		s3[i++] = buffer[j++];
	s3[ft_gnl_strlen(storage) + ft_gnl_strlen(buffer)] = '\0';
	free(storage);
	return (s3);
}