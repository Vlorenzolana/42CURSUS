/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_cmd1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:38:35 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 21:12:52 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	is_redir_tok(t_tokens *t)
{
	if (!t)
		return (0);
	return (t->type == RED_IN || t->type == RED_OUT || t->type == APPEND_OUT
		|| t->type == HEREDOC);
}

int	next_is_filename(t_tokens *t)
{
	if (!t || !t->next)
		return (0);
	if (is_redir_tok(t->next))
		return (0);
	return (1);
}

int	expect_next_token(t_tokens **tokens)
{
	if (!next_is_filename(*tokens))
	{
		syntax_error("newline");
		return (-1);
	}
	return (0);
}

int	handle_out_redir(t_cmd *cmd, t_tokens **tokens)
{
	int	append;

	append = ((*tokens)->type == APPEND_OUT);
	if (expect_next_token(tokens) < 0)
		return (-1);
	if (set_file_out(cmd, (*tokens)->next->str,
			(*tokens)->next->quote_type, append) != 0)
		return (-1);
	*tokens = (*tokens)->next;
	return (0);
}

int	handle_in_redir(t_cmd *cmd, t_tokens **tokens)
{
	if (expect_next_token(tokens) < 0)
		return (-1);
	if (set_file_in(cmd, (*tokens)->next->str,
			(*tokens)->next->quote_type) != 0)
		return (-1);
	*tokens = (*tokens)->next;
	return (0);
}
