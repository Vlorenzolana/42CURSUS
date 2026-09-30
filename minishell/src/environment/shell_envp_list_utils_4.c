/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_envp_list_utils_4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:51:05 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/21 13:07:44 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	compare_envp_nodes(t_env *a, t_env *b)
{
	return (ft_strcmp(a->name, b->name));
}

static void	swap_envp_nodes(t_env *a, t_env *b)
{
	char	*tmp_name;
	char	*tmp_value;
	bool	tmp_was_added;
	bool	tmp_visible;

	tmp_name = a->name;
	tmp_value = a->value;
	tmp_was_added = a->was_added;
	tmp_visible = a->visible;
	a->name = b->name;
	a->value = b->value;
	a->was_added = b->was_added;
	a->visible = b->visible;
	b->name = tmp_name;
	b->value = tmp_value;
	b->was_added = tmp_was_added;
	b->visible = tmp_visible;
}

void	sort_envp_list(t_env *head)
{
	t_env	*i;
	t_env	*j;
	int		swapped;

	if (!head || !head->next)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = head;
		while (i->next)
		{
			j = i->next;
			if (compare_envp_nodes(i, j) > 0)
			{
				swap_envp_nodes(i, j);
				swapped = 1;
			}
			i = i->next;
		}
	}
}
