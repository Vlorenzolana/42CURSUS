/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:50:50 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/27 12:16:59 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_signals.h"

int	g_status;

static void	sigint_handler(int signum)
{
	(void)signum;
	g_status = 130;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	setup_signal_handlers(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	sigint_handler_hd_child(int signum)
{
	(void)signum;
	g_status = 130;
	write(STDOUT_FILENO, "\n", 1);
	exit(g_status);
}

static void	sigint_handler_hd_parent(int signum)
{
	(void)signum;
	g_status = 130;
}

void	setup_signal_hd(int hd_process)
{
	if (hd_process == 0)
		signal(SIGINT, sigint_handler_hd_parent);
	else
		signal(SIGINT, sigint_handler_hd_child);
}
