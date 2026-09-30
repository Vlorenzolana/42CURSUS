/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:23:11 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/15 17:22:41 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	open_next_pipe(t_data *data, size_t i)
{
	if (i < (size_t)(data->nbr_cmds - 1))
	{
		if (pipe(data->pipes[i % 2]) == -1)
		{
			error_msg(PIPE_ERROR);
			return (1);
		}
	}
	return (0);
}

static void	cmd_iter(t_data *data, t_cmd *cmd, size_t i)
{
	if (open_next_pipe(data, i))
		return ;
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		error_msg(FORK_ERROR);
		return ;
	}
	if (cmd->pid == 0)
		child_process(data, cmd, i);
	else
		parent_process(data, cmd, i);
}

static void	cmd_loop(t_data *data, t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (cmd)
	{
		cmd_iter(data, cmd, i);
		cmd = cmd->next;
		i++;
	}
}

void	execute_pipeline(t_data *data)
{
	t_cmd	*cmd;

	if (data->nbr_cmds == 1)
	{
		one_cmd_pipeline(data);
		return ;
	}
	cmd = data->first_cmd;
	if (!cmd)
		return ;
	cmd_loop(data, cmd);
}
