/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:26:53 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/26 17:01:07 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

static void	parent(t_data *data, t_cmd *cmd)
{
	int	status;

	(void)data;
	status = 0;
	waitpid(cmd->pid, &status, 0);
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_status = 128 + WTERMSIG(status);
}

static void	child(t_data *data, t_cmd *cmd)
{
	if (cmd->file_in && file_in_redir(cmd) < 0)
		exit(1);
	if (cmd->file_out && file_out_redir(cmd) < 0)
		exit(1);
	command_exec(cmd, data);
	free_cmd_list(data->first_cmd);
	free_data(data);
	exit(g_status);
}

void	one_cmd_pipeline(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->first_cmd;
	if (!cmd)
		return ;
	if (is_builtin(cmd->args[0]))
		one_builtin_with_redir(data, cmd);
	else
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
		{
			error_msg(FORK_ERROR);
			return ;
		}
		if (cmd->pid)
			parent(data, cmd);
		else
			child(data, cmd);
	}
}
