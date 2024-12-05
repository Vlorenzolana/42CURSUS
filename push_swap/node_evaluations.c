/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_evaluations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:46:07 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 21:46:13 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Flag_cheapest iterates through the stack and marks all the "is_cheapest"
boxes as false except one. Does this by weighing each node's cost_to_push
against the next one's cost_to_push. If lower, then it is flagged true. */
void	flag_cheapest(t_stack_node *b)
{
	long			cheapest_price;
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_price = LONG_MAX;
	while (b)
	{
		b->is_cheapest = false;
		if (b->cost_to_push < cheapest_price)
		{
			cheapest_price = b->cost_to_push;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->is_cheapest = true;
}

/* This function calculates the cost of pushing each node back to stack a.
It determines if both stacks must rotate in the same direction or not by
checking if the node and it's target are both in the same half of their
stack. Cost to push will be the highest number of rotations to prepare
each stack for the push. */
void	calculate_price(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (both_in_same_half(b) && b->above_middle == true)
			b->cost_to_push = find_higher(b->index, b->target_node->index);
		else if (both_in_same_half(b) && b->above_middle == false)
			b->cost_to_push = find_higher(size_b - b->index,
					size_a - b->target_node->index);
		else
		{
			b->cost_to_push = b->index;
			if (!(b->above_middle))
				b->cost_to_push = size_b - b->index;
			if (b->target_node->above_middle)
				b->cost_to_push += b->target_node->index;
			else
				b->cost_to_push += size_a - b->target_node->index;
		}
		b = b->next;
	}
}

/* For each node in stack b, this function finds it's target node in stack a,
which is the a node on top of which the b node should sit upon. */
void	find_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*aux;
	t_stack_node	*target_node;
	long			closest_match;

	while (b)
	{
		closest_match = LONG_MAX;
		aux = a;
		while (aux)
		{
			if (aux->number > b->number && aux->number < closest_match)
			{
				target_node = aux;
				closest_match = aux->number;
			}
			aux = aux->next;
		}
		if (closest_match == LONG_MAX)
			b->target_node = find_lowest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/* Assigns to each node in the stack its relative position value at the moment.
Also marks it if it is in the upper part of the stack. 
Node->index = relative position in the stack.
Node->above_middle = "true" if node in in the top half of the stack. */
void	assign_index(t_stack_node *node)
{
	int	i;
	int	middle_index;

	if (!node)
		return ;
	middle_index = stack_size(node) / 2;
	i = 0;
	while (node)
	{
		node->index = i;
		if (i <= middle_index)
			node->above_middle = true;
		else
			node->above_middle = false;
		node = node->next;
		i++;
	}
}

/* The evaluate_nodes function controls the necessary evaluations and value
assignments to each node in the stack to later determine the optimal push.*/
void	evaluate_nodes(t_stack_node *a, t_stack_node *b)
{
	assign_index(a);
	assign_index(b);
	find_target_node(a, b);
	calculate_price(a, b);
	flag_cheapest(b);
}
