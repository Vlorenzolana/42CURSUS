/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:14:52 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/08 01:41:05 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"

static char	**get_paths_array(char *path_str)
{
	char		**paths;

	paths = ft_split(path_str, ':');
	if (!paths)
	{
		error_msg(MALLOC_ERROR);
		return (NULL);
	}
	return (paths);
}

static char	*get_cmd_path(char	*cmd, char **paths)
{
	char	*tmp;
	char	*cmd_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!cmd_path)
		{
			error_msg(MALLOC_ERROR);
			return (NULL);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	error_msg_arg(CMD_NOT_FOUND, cmd);
	return (NULL);
}

char	*find_path(char **args, t_env **shell_envp)
{
	char		*path_str;
	char		**paths_array;
	char		*cmd_path;

	path_str = get_shell_envp_value(*shell_envp, "PATH");
	if (!path_str)
	{
		error_msg_arg(NO_PATH, args[0]);
		return (NULL);
	}
	paths_array = get_paths_array(path_str);
	free(path_str);
	if (!paths_array)
		return (NULL);
	cmd_path = get_cmd_path(args[0], paths_array);
	free_array(paths_array);
	return (cmd_path);
}
