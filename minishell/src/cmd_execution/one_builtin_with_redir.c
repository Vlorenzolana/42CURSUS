/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_builtin_with_redir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:05:30 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/23 18:17:32 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

static int	save_stdio(int *in_bk, int *out_bk)
{
	if (*in_bk >= 0)
		close(*in_bk);
	*in_bk = dup(STDIN_FILENO);
	if (*in_bk < 0)
		return (-1);
	if (*out_bk >= 0)
		close(*out_bk);
	*out_bk = dup(STDOUT_FILENO);
	if (*out_bk < 0)
	{
		close(*in_bk);
		return (-1);
	}
	return (0);
}

void	one_builtin_with_redir(t_data *data, t_cmd *cmd)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (save_stdio(&data->in, &data->out) < 0)
	{
		g_status = 1;
		return ;
	}
	if (cmd->file_in && file_in_redir(cmd) < 0)
	{
		g_status = 1;
		restore_stdio(data->in, data->out);
		return ;
	}
	if (cmd->file_out && file_out_redir(cmd) < 0)
	{
		g_status = 1;
		restore_stdio(data->in, data->out);
		return ;
	}
	g_status = run_builtin(cmd, data);
	restore_stdio(data->in, data->out);
}
