/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:23:25 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/03 21:03:29 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(t_node *lst, int content)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return NULL;

	new_node->content = content; //debes introducir el valor content en el nodo
	new_node->next = new_node; // Apunta a sí mismo para hacerla circular
	return new_node;//Devuelve puntero, a la head
}