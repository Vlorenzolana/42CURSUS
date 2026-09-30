/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clasifyTokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:51:38 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/24 22:21:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

t_TokenType	clasify_token(const char *str)
{
	if (!str)
		return (ERROR);
	if (!ft_strcmp(str, "<"))
		return (RED_IN);
	if (!ft_strcmp(str, ">"))
		return (RED_OUT);
	if (!ft_strcmp(str, "<<"))
		return (HEREDOC);
	if (!ft_strcmp(str, ">>"))
		return (APPEND_OUT);
	if (str[0] == '-' && str[1])
		return (OPTION);
	if (strchr(str, '='))
		return (SETTING);
	if (!ft_strcmp(str, "|"))
		return (ERROR);
	if (is_path(str))
		return (PATH);
	return (ARG);
}

const char	*token_type_str(t_TokenType type)
{
	if (type == RED_IN)
		return ("RED_IN");
	else if (type == RED_OUT)
		return ("RED_OUT");
	else if (type == HEREDOC)
		return ("HEREDOC");
	else if (type == APPEND_OUT)
		return ("APPEND_OUT");
	else if (type == OPTION)
		return ("OPTION");
	else if (type == COMMAND)
		return ("COMMAND");
	else if (type == SETTING)
		return ("SETTING");
	else if (type == PATH)
		return ("PATH");
	else if (type == ARG)
		return ("ARG");
	else if (type == ERROR)
		return ("ERROR");
	else
		return ("UNKNOWN");
}

int	is_operator(const t_tokens *t)
{
	return (t->type == RED_IN || t->type == RED_OUT || t->type == APPEND_OUT
		|| t->type == HEREDOC);
}

int	is_token_sep(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	handle_quotes(char c, bool *in_s, bool *in_d, int *quoted)
{
	if (c == '"' && !*in_s)
	{
		*in_d = !*in_d;
		*quoted = 1;
	}
	else if (c == '\'' && !*in_d)
	{
		*in_s = !*in_s;
		*quoted = 1;
	}
}
