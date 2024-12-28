/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:47:57 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/27 18:37:53 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
/* Rotates both stacks untill either the cheapest node or it's target
are on top of their stack. */
void	twin_rotations(t_stack_node **a, t_stack_node **b,
t_stack_node *cheapest_node)
{
	if (!a || !*a || !b || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b);
	assign_index(*a);
	assign_index(*b);
}

/* Reverse rotates both stacks untill either the cheapest node or it's target
are on top of their stack. */
void	twin_reverse_rotations(t_stack_node **a, t_stack_node **b,
t_stack_node *cheapest_node)
{
	if (!a || !*a || !b || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	assign_index(*a);
	assign_index(*b);
}

/* Rotates or reverse rotates one stacks untill the top_node is on top.
"top_node" is either the cheapest node or it's target node. */
void	single_rotation(t_stack_node **stack, t_stack_node *top_node,
char name)
{
	if (!stack || !*stack || !top_node)
		return ;
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_middle)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (top_node->above_middle)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

/* Executes the correct rotations to place the node to be pushed and it's
target node on top of both stacks and then pushes it. */
void	push_optimal(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	if (!a || !*a || !b || !*b)
		return ;
	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_middle && cheapest_node->target_node->above_middle)
		twin_rotations(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle)
		&& !(cheapest_node->target_node->above_middle))
		twin_reverse_rotations(a, b, cheapest_node);
	single_rotation(b, cheapest_node, 'b');
	single_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

/* This is "the sorting engine". It works by pushing from a to b until only
three elements remain in stack a. First it solves a, then determines the
optimal push from b to a, and pushes the element to it's correct position.
 1.- Push to b until only three elemens remain in a.
 2.- Sort a as a three element case.
 3.- Determine optimal push from b to a.
 4.- Make the push.
 5.- Rinse and repeat 3 & 4.*/
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*lowest_node;
	int				size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	while (size > 3)
	{
		pb(b, a);
		size--;
	}
	solve_for_three(a);
	while (*b)
	{
		evaluate_nodes(*a, *b);
		push_optimal(a, b);
	}
	assign_index(*a);
	lowest_node = find_lowest(*a);
	if (lowest_node->above_middle == true)
		while (*a != lowest_node)
			ra(a);
	else
		while (*a != lowest_node)
			rra(a);
}