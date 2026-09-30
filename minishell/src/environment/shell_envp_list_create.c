/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_envp_list_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:54:26 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/08 22:57:10 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

/*
 * This function prints all the shell_envp list in the same format that
 * env shell command uses.
 */
void	print_shell_envp_list(t_env *shell_envp)
{
	while (shell_envp)
	{
		printf("%s=%s\n", shell_envp->name, shell_envp->value);
		shell_envp = shell_envp->next;
	}
}

/*
 * This function creates the shell_envp list from the char **envp of main.
 * Returns an int:
 * 		~ 0 : if list is created successfully.
 * 		~ MALLOC_ERROR: if there is a problem creating the list.
 */
int	shell_envp_list_create(char **envp, t_env **shell_envp)
{
	t_env	*tmp;
	int		i;

	if (!envp || !envp[0])
		return (EXIT_FAILURE);
	*shell_envp = NULL;
	i = 0;
	while (envp[i])
	{
		tmp = new_shell_envp(envp[i], false);
		if (!tmp)
		{
			free_shell_envp_list(shell_envp);
			printf("Minishell: Malloc Error: unable to allocate memory.");
			return (error_msg(MALLOC_ERROR), EXIT_FAILURE);
		}
		add_shell_envp(shell_envp, tmp);
		i++;
	}
	return (EXIT_SUCCESS);
}
