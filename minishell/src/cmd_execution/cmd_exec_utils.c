/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 01:23:41 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 17:35:02 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

void	err_cmd_not_found(const char *name, t_data *data)
{
	(void)data;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd((char *)name, 2);
	ft_putstr_fd(": command not found\n", 2);
	g_status = 127;
}

int	is_directory_path(const char *path)
{
	struct stat	st;

	if (!path)
		return (0);
	if (stat(path, &st) == -1)
		return (0);
	return (S_ISDIR(st.st_mode));
}

char	*resolve_exec_path(t_cmd *cmd, t_data *data)
{
	char	*prog;

	if (!cmd || !cmd->args || !cmd->args[0])
		return (NULL);
	prog = cmd->args[0];
	if (ft_strchr(prog, '/'))
		return (ft_strdup(prog));
	return (find_path(cmd->args, &(data->shell_envp)));
}

int	check_exec_preflight(const char *path, t_data *data)
{
	if (is_directory_path(path))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd((char *)path, 2);
		ft_putstr_fd(": is a directory\n", 2);
		g_status = 126;
		return (1);
	}
	if (access(path, X_OK) != 0)
	{
		if (errno == ENOENT)
			err_cmd_not_found(path, data);
		else
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd((char *)path, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			g_status = 126;
		}
		return (1);
	}
	return (0);
}

void	run_execve_handle(const char *path, t_cmd *cmd, t_data *data)
{
	if (ensure_envp_exec(data))
	{
		g_status = 127;
		return ;
	}
	execve(path, cmd->args, data->envp_exec);
	if (errno == ENOENT)
		err_cmd_not_found(path, data);
	else if (errno == EACCES)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd((char *)path, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		g_status = 126;
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd((char *)path, 2);
		ft_putstr_fd(": execution error\n", 2);
		g_status = 126;
	}
}
