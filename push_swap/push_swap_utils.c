/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:48:37 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 21:48:39 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Simply compare two numbers and return the bigger one. */
int	find_higher(int n, int m)
{
	if (n > m)
		return (n);
	return (m);
}

/* This function works as a logic "and" gate. If both values are true or false
returns true. In they are different returns false. */
bool	both_in_same_half(t_stack_node *b)
{
	if (b->above_middle == b->target_node->above_middle)
		return (true);
	else
		return (false);
}

/* Scans a stack looking for the "is_cheapest" flag. Returns a pointer to
the cheapest node. */
t_stack_node	*find_cheapest(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->is_cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}