/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:51:46 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 18:52:02 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	detect_was_quoted(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len >= 2 && s[0] == '\'' && s[len - 1] == '\'')
		return (2);
	if (len >= 2 && s[0] == '\"' && s[len - 1] == '\"')
		return (1);
	return (0);
}

t_tokens	*new_token(char *str)
{
	t_tokens	*tok;

	tok = (t_tokens *)malloc(sizeof(t_tokens));
	if (!tok)
		return (NULL);
	tok->str = ft_strdup(str);
	if (!tok->str)
	{
		free(tok);
		return (NULL);
	}
	tok->was_quoted = detect_was_quoted(str);
	tok->s_quoted = 0;
	tok->d_quoted = 0;
	tok->skip = 0;
	tok->type = ARG;
	tok->next = NULL;
	return (tok);
}

size_t	number_of_cmds(t_cmd *head)
{
	size_t	n;

	n = 0;
	while (head)
	{
		n++;
		head = head->next;
	}
	return (n);
}

t_tokens	**init_tokens_by_segment(size_t count)
{
	t_tokens	**arr;
	size_t		i;

	arr = (t_tokens **)malloc(sizeof(t_tokens *) * (count + 1));
	if (!arr)
	{
		perror("malloc tokens_by_segment");
		return (NULL);
	}
	i = 0;
	while (i <= count)
		arr[i++] = NULL;
	return (arr);
}

void	print_history(void)
{
	HIST_ENTRY	**entries;
	int			i;

	entries = history_list();
	if (!entries)
		return ;
	i = 0;
	while (entries[i])
	{
		printf("%d: %s\n", i + history_base, entries[i]->line);
		i++;
	}
}
