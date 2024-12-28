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

void	twin_rotate(t_node **a, t_node **b, t_node *cheapest_node)
{
	if (!a || !*a || !b || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b);
	assign_index(*a);
	assign_index(*b);
}

void	twin_reverse_rotate(t_node **a, t_node **b, t_node *cheapest_node)
{
	if (!a || !*a || !b || !*b || !cheapest_node)
		return ;
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	assign_index(*a);
	assign_index(*b);
}

void	single_rotate(t_node **stack, t_node *top_node, char name)
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

void	push_optimal(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	if (!a || !*a || !b || !*b)
		return ;
	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_middle && cheapest_node->target_node->above_middle)
		twin_rotate(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle)
		&& !(cheapest_node->target_node->above_middle))
		twin_reverse_rotate(a, b, cheapest_node);
	single_rotate(b, cheapest_node, 'b');
	single_rotate(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*lowest_node;
	int		size;

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
