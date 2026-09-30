/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:51:02 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 18:51:04 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	handle_token_alloc_fail(char **segments, char *line)
{
	free_array(segments);
	free(line);
	return (0);
}

t_pipes	*init_struct(t_pipes *args)
{
	args = (t_pipes *)malloc(sizeof(t_pipes));
	if (!args)
		return (NULL);
	args->index = 0;
	args->str = NULL;
	args->next = NULL;
	return (args);
}

int	init_pipe_segments(char *line, char ***segments, size_t *n)
{
	if (is_open(line) || has_invalid_pipe_usage(line))
	{
		write(1, "Syntax error\n", 13);
		return (0);
	}
	*segments = ft_minisplit(line, '|', n);
	if (!*segments)
		return (0);
	return (1);
}
