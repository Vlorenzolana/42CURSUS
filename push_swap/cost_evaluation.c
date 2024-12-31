/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_evaluation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:02:21 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/31 13:35:07 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	individual_cost(t_node *b, int size_a, int size_b)
{
	int	cost;

	cost = 0;
	if (b->top_half)
		cost = b->index;
	else
		cost = size_b - b->index;
	if (b->target->top_half)
		cost += b->target->index;
	else
		cost += size_a - b->target->index;
	return (cost);
}

static int	same_half_cost(t_node *b, int size_a, int size_b)
{
	if (b->top_half)
		return (get_higher(b->index, b->target->index));
	else
		return (get_higher(size_b - b->index, size_a - b->target->index));
}

void	cost_calculation(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (same_half(b))
			b->cost = same_half_cost(b, size_a, size_b);
		else
			b->cost = individual_cost(b, size_a, size_b);
		b = b->next;
	}
}

void	this_half(t_node *node)
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
			node->top_half = true;
		else
			node->top_half = false;
		node = node->next;
		i++;
	}
}

void	eval_cost(t_node *a, t_node *b)
{
	this_half(a);
	this_half(b);
	get_target(a, b);
	cost_calculation(a, b);
	flag_cheapest(b);
}
