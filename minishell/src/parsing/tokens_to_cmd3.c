/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_cmd3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:10:06 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 20:23:13 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	append_arg(t_cmd *cmd, const char *arg, t_quote_type quote_type, size_t *i)
{
	char	**newv;
	size_t	n;

	if (!cmd || !arg || !i)
		return (-1);
	n = 0;
	while (cmd->args && cmd->args[n])
		n++;
	newv = (char **)ft_calloc(n + 2, sizeof(char *));
	if (!newv)
		return (-1);
	if (n)
		ft_memcpy(newv, cmd->args, n * sizeof(char *));
	newv[n] = ft_strdup(arg);
	if (quote_type == SINGLE_QUOTE)
		strip_quotes_inplace(newv[n]);
	if (!newv[n])
		return (free(newv), -1);
	free(cmd->args);
	cmd->args = newv;
	*i = n + 1;
	return (0);
}

void	strip_quotes_inplace(char *s)
{
	size_t	i;
	size_t	j;
	char	quote;

	if (!s)
		return ;
	i = 0;
	j = 0;
	quote = 0;
	while (s[i])
	{
		if (!quote && (s[i] == '\'' || s[i] == '\"'))
			quote = s[i];
		else if (quote && s[i] == quote)
			quote = 0;
		else
		{
			s[j] = s[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
}

int	fill_cmd_args(t_cmd *cmd, t_tokens *t, t_env *env)
{
	size_t	i;
	int		rc;

	i = 0;
	while (t)
	{
		if (is_arglike(t))
		{
			if (append_arg(cmd, t->str, t->quote_type, &i) != 0)
				return (-1);
		}
		else if (is_redir_tok(t))
		{
			rc = handle_redirs_and_heredoc(cmd, &t, env);
			if (rc != 0)
				return (rc);
			if (t)
				t = t->next;
			continue ;
		}
		t = t->next;
	}
	return (0);
}
