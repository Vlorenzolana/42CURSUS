/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:10:22 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/21 11:39:17 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	is_echo_n_flag(const char *s)
{
	size_t	i;

	if (!s || s[0] != '-')
		return (0);
	i = 1;
	if (!s[i])
		return (0);
	while (s[i] == 'n')
		i++;
	return (s[i] == '\0');
}

int	shell_echo(char **args, t_data *data)
{
	int	i;
	int	print_newline;

	(void)data;
	i = 0;
	print_newline = 1;
	while (args[i] && is_echo_n_flag(args[i]))
	{
		print_newline = 0;
		i++;
	}
	while (args[i])
	{
		write(STDOUT_FILENO, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (print_newline)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
