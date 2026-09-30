/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expands2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:53:00 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/24 21:56:59 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

extern int	g_status;

static int	do_step(const t_exctx *c, size_t *i, int *sq, int *dq)
{
	int	r;

	if (ex_toggle_quotes(c->s, i, sq, dq))
		return (0);
	if (!*sq && c->s[*i] == '\\')
	{
		r = process_backslash(c->s, i, *dq, c->out);
		if (r < 0)
			return (-1);
		return (0);
	}
	if (!*sq && c->s[*i] == '$')
	{
		r = process_dollar(c->s, i, c->out, c->env);
		if (r < 0)
			return (-1);
		if (r > 0)
			return (0);
	}
	if (append_char(c->out, c->s[*i]) != 0)
		return (-1);
	(*i)++;
	return (0);
}

static char	*expand_core_loop(const char *s, t_env *env, char *out)
{
	size_t	i;
	int		sq;
	int		dq;
	t_exctx	c;

	c.s = s;
	c.env = env;
	c.out = &out;
	i = 0;
	sq = 0;
	dq = 0;
	while (s[i])
	{
		if (do_step(&c, &i, &sq, &dq) < 0)
			return (free(out), NULL);
	}
	return (out);
}

char	*expand_core(const char *s, t_env *env)
{
	char	*out;

	if (!s)
		return (NULL);
	out = ft_strdup("");
	if (!out)
		return (NULL);
	return (expand_core_loop(s, env, out));
}
