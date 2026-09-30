/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:48:40 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/24 20:31:05 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

const char	*skip_space(const char *s)
{
	while ((*s == ' ' || *s == '\t') && *s != 0)
		s++;
	return (s);
}

static void	aux_poly(const char *s, size_t *i, t_qctx *q)
{
	while (s[*i])
	{
		handle_quotes(s[*i], &q->in_s, &q->in_d, q->was_quoted);
		if (!q->in_s && !q->in_d && (s[*i] == ' ' || is_token_sep(s[*i])))
			break ;
		(*i)++;
	}
}

char	*poly_substr(const char *s, size_t *i, int *was_quoted)
{
	size_t	start;
	t_qctx	q;

	start = *i;
	q.in_s = false;
	q.in_d = false;
	q.was_quoted = was_quoted;
	*was_quoted = 0;
	if (is_token_sep(s[*i]))
	{
		if ((s[*i] == '<' || s[*i] == '>') && s[*i + 1] == s[*i])
			*i += 2;
		else
			(*i)++;
		return (ft_substr(s, start, *i - start));
	}
	aux_poly(s, i, &q);
	if (q.in_s || q.in_d)
		return (NULL);
	return (ft_substr(s, start, *i - start));
}
