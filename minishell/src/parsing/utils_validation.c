/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:41:37 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 17:32:23 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	has_invalid_pipe_usage(const char *s)
{
	int		i;
	bool	pipe_found;

	i = 0;
	pipe_found = false;
	while (s[i])
	{
		if (s[i] == '|')
		{
			if (pipe_found || i == 0 || !s[i + 1] || s[i + 1] == '|')
				return (1);
			pipe_found = true;
		}
		else if (s[i] != ' ')
			pipe_found = false;
		i++;
	}
	return (0);
}
