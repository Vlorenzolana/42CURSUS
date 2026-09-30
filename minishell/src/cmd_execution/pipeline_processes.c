/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:18:35 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/26 18:19:24 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

static void	close_safe(int *fd)
{
	if (fd && *fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}

static void	child_stdio(t_data *d, t_cmd *cmd, size_t i)
{
	int	read_fd;
	int	write_fd;

	if (i == 0)
		read_fd = -1;
	else
		read_fd = d->pipes[(i + 1) % 2][R_PIPE];
	if (i == (size_t)(d->nbr_cmds - 1))
		write_fd = -1;
	else
		write_fd = d->pipes[i % 2][W_PIPE];
	if (read_fd >= 0 && !cmd->file_in)
		dup2(read_fd, STDIN_FILENO);
	if (write_fd >= 0 && !cmd->file_out)
		dup2(write_fd, STDOUT_FILENO);
	close_safe(&d->pipes[0][R_PIPE]);
	close_safe(&d->pipes[0][W_PIPE]);
	close_safe(&d->pipes[1][R_PIPE]);
	close_safe(&d->pipes[1][W_PIPE]);
}

void	child_process(t_data *data, t_cmd *cmd, size_t i)
{
	if (file_in_redir(cmd) < 0 || file_out_redir(cmd) < 0)
		exit(1);
	child_stdio(data, cmd, i);
	command_exec(cmd, data);
	exit(g_status);
}

static void	wait_all_children(t_data *data, t_cmd *head)
{
	int		st;
	int		status;
	t_cmd	*cur;

	(void)data;
	status = 0;
	cur = head;
	while (cur)
	{
		if (cur->pid > 0 && waitpid(cur->pid, &st, 0) > 0)
		{
			if (WIFEXITED(st))
				status = WEXITSTATUS(st);
			else if (WIFSIGNALED(st))
				status = 128 + WTERMSIG(st);
		}
		cur = cur->next;
	}
	g_status = status;
}

void	parent_process(t_data *data, t_cmd *cmd, size_t i)
{
	(void)cmd;
	if (i > 0)
	{
		close_safe(&data->pipes[(i + 1) % 2][R_PIPE]);
		close_safe(&data->pipes[(i + 1) % 2][W_PIPE]);
	}
	wait_all_children(data, data->first_cmd);
}
