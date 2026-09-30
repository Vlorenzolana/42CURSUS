/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:25:36 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/21 15:39:13 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

static void	fill_data(t_data *data)
{
	data->g_builtin[0] = (t_builtin){.name = "exit", .foo = shell_exit};
	data->g_builtin[1] = (t_builtin){.name = "env", .foo = shell_env};
	data->g_builtin[2] = (t_builtin){.name = "echo", .foo = shell_echo};
	data->g_builtin[3] = (t_builtin){.name = "pwd", .foo = shell_pwd};
	data->g_builtin[4] = (t_builtin){.name = "cd", .foo = shell_cd};
	data->g_builtin[5] = (t_builtin){.name = "export", .foo = shell_export};
	data->g_builtin[6] = (t_builtin){.name = "unset", .foo = shell_unset};
	data->g_builtin[7] = (t_builtin){.name = NULL, .foo = NULL};
	data->shell_envp = NULL;
	data->first_cmd = NULL;
	data->nbr_cmds = 0;
	data->envp_exec = NULL;
	data->nbr_cmds = 0;
	g_status = 0;
	data->pipes[0][R_PIPE] = -1;
	data->pipes[0][W_PIPE] = -1;
	data->pipes[1][R_PIPE] = -1;
	data->pipes[1][W_PIPE] = -1;
	data->in = -1;
	data->out = -1;
	data->tokens_by_segment = NULL;
}

int	data_init(t_data *data, char **envp)
{
	fill_data(data);
	if (shell_envp_list_create(envp, &(data->shell_envp)))
	{
		data->shell_envp = NULL;
		return (EXIT_FAILURE);
	}
	if (resync_env_array(&data->envp_exec, data->shell_envp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	close_pipes(t_data *data)
{
	if (data->pipes[0][R_PIPE] > 0)
		close(data->pipes[0][R_PIPE]);
	if (data->pipes[0][W_PIPE] > 0)
		close(data->pipes[0][W_PIPE]);
	if (data->pipes[1][R_PIPE] > 0)
		close(data->pipes[1][R_PIPE]);
	if (data->pipes[1][W_PIPE] > 0)
		close(data->pipes[1][W_PIPE]);
}

void	free_data(t_data *data)
{
	free_envp_array(data->envp_exec);
	data->envp_exec = NULL;
	free_shell_envp_list(&(data->shell_envp));
	rl_clear_history();
}
