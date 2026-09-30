/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:21:38 by dalabrad          #+#    #+#             */
/*   Updated: 2025/07/28 16:30:43 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	shell_pwd(char **args, t_data *data)
{
	char	*directory;

	directory = NULL;
	(void)data;
	(void)args;
	directory = getcwd(NULL, 0);
	if (!directory)
		return (ft_putstr_fd("Error in getcwd()\n", 2), 127);
	printf("%s\n", directory);
	free(directory);
	return (EXIT_SUCCESS);
}
