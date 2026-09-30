/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:38:55 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/16 15:24:46 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

static void	exec_external(t_cmd *cmd, t_data *data)
{
	char	*path;

	path = resolve_exec_path(cmd, data);
	if (!path)
	{
		g_status = 127;
		return ;
	}
	if (check_exec_preflight(path, data))
		return (free(path));
	run_execve_handle(path, cmd, data);
	free(path);
}

void	command_exec(t_cmd *cmd, t_data *data)
{
	if (!cmd || !cmd->args || !cmd->args[0])
	{
		g_status = 0;
		return ;
	}
	if (is_builtin(cmd->args[0]))
		g_status = run_builtin(cmd, data);
	else
		exec_external(cmd, data);
}
