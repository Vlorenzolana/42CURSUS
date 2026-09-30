/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:59:27 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 20:37:03 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	unquote_is_quoted(char **s)
{
	int		q;
	size_t	len;

	q = 0;
	if (!s || !*s || !**s)
		return (0);
	len = ft_strlen(*s);
	if ((**s == '\'' || **s == '\"') && (*s)[ft_strlen(*s) - 1] == **s)
	{
		q = 1;
		strip_quotes_inplace(*s);
	}
	return (q);
}

static int	handle_heredoc_case(t_cmd *cmd, t_tokens **tok, t_env *env)
{
	char	*delim;
	int		quoted;
	int		rc;

	if (!next_is_filename(*tok))
		return (syntax_error("newline"), -1);
	delim = ft_strdup((*tok)->next->str);
	if (!delim)
		return (-1);
	quoted = unquote_is_quoted(&delim);
	rc = run_heredoc(delim, quoted, env);
	free(delim);
	if (rc == 1)
		return (-2);
	if (rc != 0)
		return (-1);
	if (set_file_in(cmd, "/tmp/minishell_heredoc", NO_QUOTE) != 0)
		return (-1);
	*tok = (*tok)->next;
	return (0);
}

int	handle_redirs_and_heredoc(t_cmd *cmd, t_tokens **tokens, t_env *env)
{
	if ((*tokens)->type == RED_OUT || (*tokens)->type == APPEND_OUT)
		return (handle_out_redir(cmd, tokens));
	if ((*tokens)->type == RED_IN)
		return (handle_in_redir(cmd, tokens));
	if ((*tokens)->type == HEREDOC)
		return (handle_heredoc_case(cmd, tokens, env));
	return (0);
}
