/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:51:29 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/24 22:20:28 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	fail_and_free(char **array)
{
	free_array(array);
	return (0);
}

static int	handle_open_check(const char *s, size_t k, size_t j, char **array)
{
	char	*tmp;

	tmp = ft_substr(s, k, j - k);
	if (!tmp)
		return (0);
	if (is_open(tmp))
	{
		free(tmp);
		write(1, "Syntax error\n", 14);
		if (array != NULL)
			fail_and_free(array);
		return (0);
	}
	free(tmp);
	return (1);
}

size_t	is_open(const char *s)
{
	int	i;
	int	in_s;
	int	in_d;
	int	esc;

	in_s = 0;
	in_d = 0;
	i = 0;
	while (s[i] != '\0')
	{
		esc = is_escaped(s, i, in_s);
		update_quote_state(s[i], &in_s, &in_d, esc);
		i++;
	}
	if (in_s == 1 || in_d == 1)
		return (1);
	return (0);
}

char	**split2array(const char *s, char c, char **array, size_t w_count)
{
	size_t	i;
	size_t	pos;
	size_t	len;

	i = 0;
	pos = 0;
	while (i < w_count)
	{
		len = quoted_field_len(&s[pos], c);
		if (len == 0)
			return (free_array(array), NULL);
		if (!handle_open_check(s, pos, pos + len, array))
			return (NULL);
		array[i] = ft_substr(s, pos, len);
		if (!array[i])
			return (free_array(array), NULL);
		pos += len;
		if (s[pos] == c)
			pos++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_minisplit(const char *s, char c, size_t *n)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	s = skip_space(s);
	if (s == NULL || *s == '\0')
	{
		*n = 0;
		return (NULL);
	}
	if (is_open(s))
	{
		write(1, "Syntax error\n", 14);
		*n = 0;
		return (NULL);
	}
	*n = count_splitted((char *)s, c);
	if (*n == 0)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (*n + 1));
	if (!array)
		return (NULL);
	if (!split2array(s, c, array, *n))
		return (NULL);
	return (array);
}
