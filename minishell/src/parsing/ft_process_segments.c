/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_segments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:36:10 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 17:27:53 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

void	process_single_segment(char *segment, t_tokens **token, t_data *data,
		t_cmd **first_cmd)
{
	t_cmd	*current;
	t_cmd	*last;
	size_t	word_count;

	word_count = 0;
	*token = check_args_fixed(segment, &word_count);
	if (!*token)
		return ;
	expand_tokens(*token, data->shell_envp);
	current = tokens_to_cmd(*token, data->shell_envp);
	if (!current)
	{
		free_tokens_list(*token);
		*token = NULL;
		return ;
	}
	if (!*first_cmd)
		*first_cmd = current;
	else
	{
		last = last_cmd(*first_cmd);
		last->next = current;
	}
}

void	process_segments(char **segments, t_tokens **tokens, size_t n,
		t_data *data)
{
	size_t	i;

	data->first_cmd = NULL;
	i = 0;
	while (i < n)
	{
		process_single_segment(segments[i], &tokens[i], data, &data->first_cmd);
		i++;
	}
	data->nbr_cmds = number_of_cmds(data->first_cmd);
}
