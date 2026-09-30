/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:08:15 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/09 17:25:53 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	export_pwd(t_data *data, char *pwd_path, char *pwd_type)
{
	char	**tmp;

	tmp = (char **)malloc(2 * sizeof(char *));
	if (!tmp)
		return (error_msg(MALLOC_ERROR));
	tmp[0] = ft_strjoin(pwd_type, pwd_path);
	if (!tmp[0])
	{
		free(tmp);
		return (error_msg(MALLOC_ERROR));
	}
	tmp[1] = NULL;
	shell_export(tmp, data);
	free_array(tmp);
	return (EXIT_SUCCESS);
}

static int	cd_execute(t_data *data, char *target)
{
	char	*old_pwd;
	char	*pwd;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (error_msg(MALLOC_ERROR));
	if (chdir(target))
		return (free(old_pwd), free(target), error_msg(CHDIR_ERROR));
	export_pwd(data, old_pwd, "OLDPWD=");
	free(old_pwd);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (error_msg(MALLOC_ERROR));
	export_pwd(data, pwd, "PWD=");
	return (free(pwd), free(target), EXIT_SUCCESS);
}

int	shell_cd(char **args, t_data *data)
{
	char	*target;

	if (array_size(args) > 1)
		return (error_msg(CD_ERROR));
	if (!args[0])
	{
		target = get_shell_envp_value(data->shell_envp, "HOME");
		if (!target)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	}
	else
	{
		if (access(args[0], F_OK))
			return (error_msg_arg(CD_NO_DIR, args[0]));
		if (access(args[0], X_OK))
			return (error_msg_arg(CD_NO_PERM, args[0]));
		target = ft_strdup(args[0]);
	}
	return (cd_execute(data, target));
}
