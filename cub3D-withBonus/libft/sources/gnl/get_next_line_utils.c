/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:34:34 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/10 19:59:51 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin_special(char const *s1, char const *s2, int bytes_read)
{
	char	*str;
	int		s1_len;
	int		i;

	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	i = -1;
	str = malloc((s1_len + bytes_read + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1_len != 0)
	{
		while (s1[++i])
			str[i] = s1[i];
		i--;
	}
	while (++i - s1_len < bytes_read)
		str[i] = s2[i - s1_len];
	str[s1_len + bytes_read] = '\0';
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*temp;
	int		i;

	if (!s)
		return (NULL);
	temp = (char *)s;
	i = 0;
	while (temp[i])
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&temp[i]);
	return (NULL);
}

char	*ft_strdup_gnl(const char *s1)
{
	int		i;
	char	*str;

	str = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

int	line_len(char *buffer)
{
	int	len;

	len = 0;
	while (*buffer != '\n' && *buffer)
	{
		len++;
		buffer++;
	}
	if (*buffer == '\n')
		len++;
	return (len);
}
