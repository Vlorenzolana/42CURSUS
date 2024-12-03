/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:12:22 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/03 21:00:25 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_node	*ft_lstlast(t_node *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}

int	ft_get_int(int index, t_node *lst)
{
	int	i;

	i = 0;
	while (i < index)
	{
		i++;
		lst = lst->next;
	}
	return (lst->content);
}

t_node *ft_addfront(t_node *head, int content)
{
	t_node *new_node = create_node(head, content);
	if (!(head))
	{
	head = new_node;/// Asignar el nuevo nodo como cabeza de lista
	}
	else
		{
		t_node *temp = head;
		temp = temp->next;
		while (temp->next!=(head)) 
		{
			temp = temp->next;
		}// Ahora el (ultimo)*temp apunta a NULL
	new_node->next = head;// Actualiza la cabeza para que sea el nuevo nodo
	}
	return(head);
}