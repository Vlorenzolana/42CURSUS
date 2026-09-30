/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:51:18 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 18:50:32 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

void	update_quote_state(char c, int *in_s, int *in_d, int prev_escape)
{
	if (*in_s == 0 && *in_d == 0)
	{
		if (c == '\'')
			*in_s = 1;
		else if (c == '"')
			*in_d = 1;
	}
	else if (*in_s == 1)
	{
		if (c == '\'')
			*in_s = 0;
	}
	else if (*in_d == 1)
	{
		if (c == '"' && prev_escape == 0)
			*in_d = 0;
	}
}

int	is_escaped(const char *s, int i, int in_single)
{
	int	backslashes;

	if (in_single == 1)
		return (0);
	backslashes = 0;
	i--;
	while (i >= 0 && s[i] == '\\')
	{
		backslashes++;
		i--;
	}
	if ((backslashes % 2) == 1)
		return (1);
	return (0);
}

size_t	quoted_field_len(const char *s, char c)
{
	size_t	len;
	int		in_s;
	int		in_d;
	int		esc;

	len = 0;
	in_s = 0;
	in_d = 0;
	while (s[len] != '\0')
	{
		esc = is_escaped(s, (int)len, in_s);
		if (s[len] == c && in_s == 0 && in_d == 0)
			break ;
		update_quote_state(s[len], &in_s, &in_d, esc);
		len++;
	}
	return (len);
}

int	is_path(const char *str)
{
	if (!str || ft_strlen(str) < 2)
		return (0);
	if (str[0] == '.' && str[1] == '/')
		return (0);
	if (str[0] == '/')
		return (1);
	if (ft_strncmp(str, "./", 2) == 0 || ft_strncmp(str, "../", 3) == 0)
		return (1);
	if (ft_strchr(str, '/'))
		return (1);
	return (0);
}

int	ft_lstadd_front2(t_pipes **lst, t_pipes *new)
{
	if (!new)
		return (1);
	new->next = *lst;
	*lst = new;
	return (0);
}
