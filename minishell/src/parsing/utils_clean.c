/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:15:13 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 18:56:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	is_exit_command(char **line, t_data *data)
{
	if (line && line[0] && ft_strcmp(line[0], "exit") == 0)
	{
		shell_exit(line, data);
		return (1);
	}
	return (0);
}

t_pipes	*clean_struct(t_pipes *args)
{
	t_pipes	*temp;

	temp = NULL;
	while (args && args->next)
	{
		temp = args;
		args = args->next;
		free(temp);
		temp = NULL;
	}
	return (temp);
}

void	free_tokens_list(t_tokens *head)
{
	t_tokens	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->str)
			free(head->str);
		free(head);
		head = tmp;
	}
}

void	cleanup(char **segments, t_tokens **tokens, size_t n)
{
	size_t	j;

	free_array(segments);
	if (tokens)
	{
		j = 0;
		while (j < n)
			free_tokens_list(tokens[j++]);
		free(tokens);
	}
}
