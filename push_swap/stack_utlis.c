/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:50:38 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 21:50:45 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Counts the number of nodes in a stack. Returns the count.*/
int	stack_size(t_stack_node *node)
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

/* Checks if a stack is already sorted. Checks that each node->number 
is lower than node->next->number. Returns true if sorted.*/
bool	is_sorted(t_stack_node *node)
{
	if (!node)
		return (true);
	while (node->next)
	{
		if (node->number > node->next->number)
			return (false);
		node = node->next;
	}
	return (true);
}

/* Solves the simple case when a three node stack has to be sorted.
This can be usually done in one move, or two at most. */
void	solve_for_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	if (!a || !*a || stack_size(*a) != 3)
		return ;
	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

/* Finds and returns a pointer to the node with the highest number
(node->number) in a stack. */
t_stack_node	*find_highest(t_stack_node *node)
{
	int				highest;
	t_stack_node	*highest_node;

	if (!node)
		return (NULL);
	highest = INT_MIN;
	highest_node = NULL;
	while (node)
	{
		if (node->number > highest)
		{
			highest = node->number;
			highest_node = node;
		}
		node = node->next;
	}
	return (highest_node);
}

/* Finds and returns a pointer to the node with the lowest number
(node->number) in a stack. */
t_stack_node	*find_lowest(t_stack_node *node)
{
	int				lowest;
	t_stack_node	*lowest_node;

	if (!node)
		return (NULL);
	lowest = INT_MAX;
	lowest_node = NULL;
	while (node)
	{
		if (node->number < lowest)
		{
			lowest = node->number;
			lowest_node = node;
		}
		node = node->next;
	}
	return (lowest_node);
}
