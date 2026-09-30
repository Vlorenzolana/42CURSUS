/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:16:31 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/17 13:23:06 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	syntax_error(char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
	return (258);
}

int	error_msg(t_err error_code)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error_code == MALLOC_ERROR)
		ft_putstr_fd("malloc: unable to allocate memory\n", 2);
	else if (error_code == DUP_ERROR)
		ft_putstr_fd("dup: error redirecting file descriptor\n", 2);
	else if (error_code == CD_ERROR)
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
	else if (error_code == CHDIR_ERROR)
		ft_putstr_fd("chdir : unable to change process working directory\n", 2);
	else if (error_code == PIPE_ERROR)
		ft_putstr_fd("pipe: unable to create pipes\n", 2);
	else if (error_code == FORK_ERROR)
		ft_putstr_fd("fork: unable to create child process\n", STDERR_FILENO);
	return (error_code);
}

int	error_msg_arg(t_err error_code, char *arg)
{
	if (!arg)
		return (0);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error_code == CD_NO_DIR || error_code == CD_NO_PERM)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		if (error_code == CD_NO_DIR)
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		else
			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	}
	else if (error_code == NO_PATH)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	else if (error_code == CMD_NOT_FOUND)
	{
		ft_putstr_fd("command not found: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (error_code);
}
