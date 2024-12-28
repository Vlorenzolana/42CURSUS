/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:48:37 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/27 18:14:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_higher(int n, int m)
{
	if (n > m)
		return (n);
	return (m);
}

bool	both_in_same_half(t_stack_node *b)
{
	if (b->above_middle == b->target_node->above_middle)
		return (true);
	else
		return (false);
}

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