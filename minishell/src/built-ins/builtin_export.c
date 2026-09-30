/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:20:39 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/21 12:58:58 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	valid_export_arg(char *arg)
{
	int		i;
	int		name;

	if (!arg || !ft_strchr(arg, '='))
		return (0);
	i = 0;
	name = 1;
	while (arg[i])
	{
		if (name && !ft_isalnum(arg[i]) && arg[i] != '_' && arg[i] != '=')
			return (0);
		if (arg[i] == '=')
			name = 0;
		i++;
	}
	return (1);
}

static int	split_name_value(char *arg, char **name, char **value)
{
	char	*eq;

	*name = NULL;
	*value = NULL;
	if (!arg)
		return (1);
	eq = ft_strchr(arg, '=');
	if (!eq)
		return (1);
	*name = ft_substr(arg, 0, (size_t)(eq - arg));
	*value = ft_strdup(eq + 1);
	if (!*name || !*value)
		return (free(*name), free(*value), 1);
	return (0);
}

static int	export_one(char *arg, t_env **env)
{
	char	*name;
	char	*value;
	int		err;

	if (split_name_value(arg, &name, &value))
		return (1);
	err = env_set(env, name, value);
	free(name);
	free(value);
	return (err);
}

static void	print_invalid(char *arg)
{
	ft_putstr_fd("bash: export: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier \n", 2);
}

int	shell_export(char **args, t_data *data)
{
	int	i;
	int	status;
	int	changed;

	if (!args || !args[0])
	{
		export_no_args(data->shell_envp);
		return (EXIT_SUCCESS);
	}
	i = 0;
	status = 0;
	changed = 0;
	while (args[i])
	{
		if (!valid_export_arg(args[i]))
			(print_invalid(args[i]), status = 1);
		else if (export_one(args[i], &(data->shell_envp)) == 0)
			changed = 1;
		i++;
	}
	if (changed && resync_env_array(&(data->envp_exec), data->shell_envp))
		status = 1;
	return (status);
}
