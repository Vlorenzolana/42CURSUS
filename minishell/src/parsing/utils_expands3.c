/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expands3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:58:48 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/24 22:03:08 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

extern int	g_status;

int	ex_toggle_quotes(const char *s, size_t *i, int *sq, int *dq)
{
	if (s[*i] == '\'' && !*dq)
	{
		*sq = !*sq;
		(*i)++;
		return (1);
	}
	if (s[*i] == '\"' && !*sq)
	{
		*dq = !*dq;
		(*i)++;
		return (1);
	}
	return (0);
}

int	ex_bs_in_dq(const char *s, size_t *i, char **out)
{
	if (s[*i + 1] == '$' || s[*i + 1] == '\"' || s[*i + 1] == '\\')
	{
		*out = ft_strjoin_char_free(*out, s[*i + 1]);
		if (!*out)
			return (-1);
		*i += 2;
		return (0);
	}
	*out = ft_strjoin_char_free(*out, '\\');
	if (!*out)
		return (-1);
	(*i)++;
	return (0);
}

int	ex_bs_plain(const char *s, size_t *i, char **out)
{
	if (s[*i + 1])
	{
		*out = ft_strjoin_char_free(*out, s[*i + 1]);
		if (!*out)
			return (-1);
		*i += 2;
		return (0);
	}
	*out = ft_strjoin_char_free(*out, '\\');
	if (!*out)
		return (-1);
	(*i)++;
	return (0);
}

int	ex_handle_dollar(const char *s, size_t *i, char **out, t_env *env)
{
	if (s[*i] != '$')
		return (0);
	if (s[*i + 1] == '?')
	{
		*i += 2;
		if (handle_exit_status(out, g_status))
			return (-1);
		return (1);
	}
	if (s[*i + 1] && (ft_isalnum((unsigned char)s[*i + 1]) || s[*i + 1] == '_'))
	{
		(*i)++;
		*i = handle_variable(s, *i, out, env);
		if (*out)
			return (1);
		return (-1);
	}
	*out = ft_strjoin_char_free(*out, '$');
	if (!*out)
		return (-1);
	(*i)++;
	return (1);
}

int	append_char(char **out, char c)
{
	*out = ft_strjoin_char_free(*out, c);
	if (!*out)
		return (-1);
	return (0);
}
