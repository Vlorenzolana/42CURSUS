/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:32:39 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 18:49:34 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

static inline t_quote_type	map_quote_type_from_int(int q)
{
	if (q == 2)
		return (SINGLE_QUOTE);
	if (q == 1)
		return (DOUBLE_QUOTE);
	return (NO_QUOTE);
}

static int	detect_outer_quote_type(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len >= 2)
	{
		if (s[0] == '\'' && s[len - 1] == '\'')
			return (2);
		if (s[0] == '\"' && s[len - 1] == '\"')
			return (1);
	}
	return (0);
}

static void	set_token_quote_flags(t_tokens *tok)
{
	int	q;

	if (!tok || !tok->str)
		return ;
	q = detect_outer_quote_type(tok->str);
	tok->quote_type = map_quote_type_from_int(q);
	if (tok->str[0] == '\0' && q != 0)
		tok->was_quoted = 1;
}

t_tokens	*create_token(const char *input, size_t *k, size_t *i_words)
{
	t_tokens	*new_tok;

	new_tok = malloc(sizeof(t_tokens));
	if (!new_tok)
		return (NULL);
	new_tok->str = poly_substr(input, k, &new_tok->was_quoted);
	if (!new_tok->str)
	{
		free(new_tok);
		return (NULL);
	}
	new_tok->type = clasify_token(new_tok->str);
	new_tok->s_quoted = 0;
	new_tok->d_quoted = 0;
	new_tok->skip = 0;
	new_tok->next = NULL;
	set_token_quote_flags(new_tok);
	(*i_words)++;
	return (new_tok);
}

t_tokens	*check_args_fixed(const char *input, size_t *i_words)
{
	t_tokens	*head;
	t_tokens	*curr;
	t_tokens	*new_tok;
	size_t		k;

	head = NULL;
	curr = NULL;
	k = 0;
	while (input[k])
	{
		while (input[k] == ' ')
			k++;
		if (!input[k])
			break ;
		new_tok = create_token(input, &k, i_words);
		if (!new_tok)
			return (free_tokens_list(head), NULL);
		if (!head)
			head = new_tok;
		else
			curr->next = new_tok;
		curr = new_tok;
	}
	set_command_type(head);
	return (head);
}
