/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:13:03 by dalabrad          #+#    #+#             */
/*   Updated: 2025/07/28 16:36:21 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	shell_env(char **args, t_data *data)
{
	t_env	**shell_envp;

	shell_envp = &(data->shell_envp);
	(void)args;
	if (!shell_envp || !(*shell_envp))
		return (EXIT_FAILURE);
	print_shell_envp_list(*shell_envp);
	return (EXIT_SUCCESS);
}
