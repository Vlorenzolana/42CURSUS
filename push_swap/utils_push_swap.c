/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:48:37 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/28 09:56:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_higher(int n, int m)
{
	if (n > m)
		return (n);
	return (m);
}

bool	same_part(t_node *b)
{
	if (b->above_middle == b->target_node->above_middle)
		return (true);
	else
		return (false);
}

t_node	*find_cheapest(t_node *node)
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
