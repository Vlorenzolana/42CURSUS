/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:50:38 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/28 13:08:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *node)
{
	int	size;

	if (!node)
		return (0);
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

bool	sorted(t_node *node)
{
	if (!node)
		return (true);
	while (node->next)
	{
		if (node->num > node->next->num)
			return (false);
		node = node->next;
	}
	return (true);
}

void	sort_three(t_node **a)
{
	t_node	*highest_node;

	if (!a || !*a || stack_size(*a) != 3)
		return ;
	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

t_node	*find_highest(t_node *node)
{
	int		highest;
	t_node	*highest_node;

	if (!node)
		return (NULL);
	highest = INT_MIN;
	highest_node = NULL;
	while (node)
	{
		if (node->num > highest)
		{
			highest = node->num;
			highest_node = node;
		}
		node = node->next;
	}
	return (highest_node);
}

t_node	*find_lowest(t_node *node)
{
	int		lowest;
	t_node	*lowest_node;

	if (!node)
		return (NULL);
	lowest = INT_MAX;
	lowest_node = NULL;
	while (node)
	{
		if (node->num < lowest)
		{
			lowest = node->num;
			lowest_node = node;
		}
		node = node->next;
	}
	return (lowest_node);
}
