/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:35:00 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 17:20:08 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_utils.h"
#include "minishell_exec.h"
#include "minishell_parsing.h"
#include "minishell_signals.h"

int extern	g_status;

size_t	splitted_len(const char *s, char c)
{
	(void)c;
	return (quoted_field_len(s, '|'));
}

void	set_command_type(t_tokens *head)
{
	t_tokens	*t;
	int			found;

	t = head;
	found = 0;
	while (t)
	{
		if (!found && !is_operator(t) && t->type != ERROR)
		{
			t->type = COMMAND;
			found = 1;
		}
		t = t->next;
	}
}

void	expand_tokens(t_tokens *head, t_env *env)
{
	t_tokens	*t;
	char		*newstr;

	t = head;
	while (t)
	{
		if ((t->str && *t->str) || t->was_quoted)
		{
			if (t->quote_type != SINGLE_QUOTE)
			{
				newstr = expand_core(t->str, env);
				if (newstr)
				{
					free(t->str);
					t->str = newstr;
				}
			}
		}
		t = t->next;
	}
}
