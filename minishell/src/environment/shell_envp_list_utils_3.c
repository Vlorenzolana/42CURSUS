/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_envp_list_utils_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:47:53 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/21 13:04:26 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static void	free_malloc_error(t_env *new_head)
{
	t_env	*temp;

	while (new_head)
	{
		temp = new_head;
		new_head = new_head->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}

static void	copy_values(t_env *new_node, t_env *current)
{
	new_node->was_added = current->was_added;
	new_node->name = ft_strdup (current->name);
	new_node->value = ft_strdup (current->value);
	new_node->visible = current->visible;
	new_node->next = NULL;
}

t_env	*copy_envp_list(t_env *shell_envp)
{
	t_env	*new_head;
	t_env	*new_tail;
	t_env	*current;
	t_env	*new_node;

	new_head = NULL;
	new_tail = NULL;
	current = shell_envp;
	while (current != NULL)
	{
		new_node = (t_env *)malloc(sizeof(t_env));
		if (!new_node)
		{
			free_malloc_error(new_head);
			return (NULL);
		}
		copy_values(new_node, current);
		if (new_tail == NULL)
			new_head = new_node;
		else
			new_tail->next = new_node;
		new_tail = new_node;
		current = current->next;
	}
	return (new_head);
}
