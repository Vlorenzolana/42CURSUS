/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:18:50 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/21 16:20:16 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

void	close_dups(t_data *data)
{
	if (data->in >= 0)
		close(data->in);
	if (data->out >= 0)
		close(data->out);
}

int	shell_exit(char **args, t_data *data)
{
	int		exit_code;
	bool	error;

	error = false;
	if (data && (data->nbr_cmds == 1 || data->nbr_cmds == 0))
		printf("exit\n");
	if (!args || !args[0])
		exit_code = g_status;
	else
	{
		exit_code = get_exit_code(args[0], &error);
		if (error)
		{
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
			exit_code = 2;
		}
		else if (args[1])
			return (ft_putstr_fd("minishell: exit: too many arguments\n",
					2), 1);
	}
	close_dups(data);
	free_data(data);
	free_cmd_list(data->first_cmd);
	exit(exit_code);
	return (exit_code);
}
