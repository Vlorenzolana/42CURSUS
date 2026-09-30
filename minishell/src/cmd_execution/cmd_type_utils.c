/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_type_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:46:09 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/15 17:07:47 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

// Export; environment data resync,util before execve
int	ensure_envp_exec(t_data *data)
{
	if (!data)
		return (1);
	if (!data->envp_exec)
	{
		if (resync_env_array(&(data->envp_exec), data->shell_envp))
			return (1);
	}
	return (0);
}

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->file_in = NULL;
	cmd->file_out = NULL;
	cmd->append_out = false;
	cmd->pid = -1;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*last_cmd(t_cmd *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

/* Pedida por main_utils.c, pipeline_processes.c, builtin_exit.c, etc. */
void	free_cmd_list(t_cmd *cmd)
{
	t_cmd	*tmp;
	size_t	i;

	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i])
				free(cmd->args[i++]);
			free(cmd->args);
		}
		if (cmd->file_in)
			free(cmd->file_in);
		if (cmd->file_out)
			free(cmd->file_out);
		free(cmd);
		cmd = tmp;
	}
}
