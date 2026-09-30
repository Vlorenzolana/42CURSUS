/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:20:48 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/24 22:21:06 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static size_t	count_splitted_loop(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		len = quoted_field_len(&s[i], c);
		if (len == 0)
			break ;
		count++;
		i += len;
		if (s[i] == c)
			i++;
	}
	return (count);
}

size_t	count_splitted(char *s, char c)
{
	if (!s || *s == '\0')
		return (0);
	s = (char *)skip_space(s);
	if (*s == '\0')
		return (0);
	if (*s == c)
	{
		write(1, "Syntax error\n", 13);
		return (0);
	}
	return (count_splitted_loop(s, c));
}
