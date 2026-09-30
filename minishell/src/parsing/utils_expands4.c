/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expands4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:49:23 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 22:53:27 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

extern int	g_status;

int	process_backslash(const char *s, size_t *i, int dq, char **out)
{
	int	r;

	if (!dq)
		r = ex_bs_plain(s, i, out);
	else
		r = ex_bs_in_dq(s, i, out);
	return (r);
}

int	process_dollar(const char *s, size_t *i, char **out, t_env *env)
{
	return (ex_handle_dollar(s, i, out, env));
}

int	step_backslash(const char *s, size_t *i, int dq, char **out)
{
	int	r;

	if (s[*i] != '\\')
		return (0);
	r = process_backslash(s, i, dq, out);
	if (r < 0)
		return (-1);
	return (1);
}

int	step_dollar(const char *s, size_t *i, char **out, t_env *env)
{
	int	r;

	if (s[*i] != '$')
		return (0);
	r = process_dollar(s, i, out, env);
	if (r < 0)
		return (-1);
	if (r > 0)
		return (1);
	return (0);
}

int	append_and_advance(const char *s, size_t *i, char **out)
{
	if (append_char(out, s[*i]) != 0)
		return (-1);
	(*i)++;
	return (0);
}
