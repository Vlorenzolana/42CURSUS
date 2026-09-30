/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:10:54 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/21 12:59:24 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

void	export_no_args(t_env *shell_envp)
{
	t_env	*copy_envp;
	t_env	*tmp;

	copy_envp = copy_envp_list(shell_envp);
	sort_envp_list(copy_envp);
	tmp = copy_envp;
	while (tmp)
	{
		ft_putstr("declare -x ");
		ft_putstr(tmp->name);
		ft_putstr("=\"");
		ft_putstr(tmp->value);
		ft_putstr("\"\n");
		tmp = tmp->next;
	}
	free_shell_envp_list(&copy_envp);
}
