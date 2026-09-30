/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_envp_array_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:41:17 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/08 22:57:06 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

char	**shell_envp_array_create(t_env *shell_envp)
{
	char	**arr;
	size_t	i;
	size_t	size;

	size = shell_envp_size(shell_envp);
	if (!shell_envp || size == 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	arr[size] = NULL;
	i = 0;
	while (shell_envp && i < size)
	{
		arr[i] = get_shell_envp_str(shell_envp);
		if (!arr[i])
		{
			free_array(arr);
			error_msg(MALLOC_ERROR);
			return (NULL);
		}
		i++;
		shell_envp = shell_envp->next;
	}
	return (arr);
}
