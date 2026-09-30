/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:53:52 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/27 12:14:17 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

extern int	g_status;

static void	hd_child_run(const char *delim, int quoted, t_env *env)
{
	setup_signal_hd(1);
	if (heredoc_loop_open(delim, quoted, env) < 0)
		exit(1);
	exit(0);
}

static int	hd_parent_wait(pid_t pid)
{
	int	st;

	setup_signal_hd(0);
	if (waitpid(pid, &st, 0) < 0)
		return (-1);
	if (WIFSIGNALED(st) && WTERMSIG(st) == SIGINT)
	{
		g_status = 130;
		return (1);
	}
	if (WIFEXITED(st) && WEXITSTATUS(st) != 0)
		return (-1);
	return (0);
}

int	run_heredoc(const char *delim, int quoted, t_env *env)
{
	pid_t	pid;
	int		rc;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
		hd_child_run(delim, quoted, env);
	rc = hd_parent_wait(pid);
	if (rc != 0)
		return (rc);
	return (0);
}

void	heredoc_eof_warning(const char *delim)
{
	ft_putstr_fd("minishell: warning: here-document" \
		" delimited by end-of-file (wanted \'", 2);
	ft_putstr_fd((char *)delim, 2);
	ft_putstr_fd("\')\n", 2);
}
