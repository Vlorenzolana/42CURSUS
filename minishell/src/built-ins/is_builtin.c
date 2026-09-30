/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:02:44 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/19 21:56:24 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	is_builtin(const char *s)
{
	if (!s || !*s)
		return (0);
	if (!ft_strcmp(s, "echo") || !ft_strcmp(s, "cd")
		|| !ft_strcmp(s, "pwd") || !ft_strcmp(s, "export")
		|| !ft_strcmp(s, "unset") || !ft_strcmp(s, "env")
		|| !ft_strcmp(s, "exit"))
		return (1);
	return (0);
}

/* Ejecuta el builtin y devuelve su status.
 * Nota: echo/pwd/exit reciben cmd->args completos.
 *       cd/export/unset/env reciben cmd->args + 1 (solo argumentos). */
int	run_builtin(t_cmd *cmd, t_data *data)
{
	char	**a;

	if (!cmd || !cmd->args || !cmd->args[0])
		return (127);
	a = cmd->args;
	if (!ft_strcmp(a[0], "echo"))
	{
		return (shell_echo(a + 1, data));
	}
	if (!ft_strcmp(a[0], "pwd"))
		return (shell_pwd(a + 1, data));
	if (!ft_strcmp(a[0], "exit"))
		return (shell_exit(a + 1, data));
	if (!ft_strcmp(a[0], "cd"))
		return (shell_cd(a + 1, data));
	if (!ft_strcmp(a[0], "export"))
		return (shell_export(a + 1, data));
	if (!ft_strcmp(a[0], "unset"))
		return (shell_unset(a + 1, data));
	if (!ft_strcmp(a[0], "env"))
		return (shell_env(a + 1, data));
	return (127);
}
