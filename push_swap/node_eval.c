/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_eval.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:46:07 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/27 15:58:04 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_cheapest(t_node *b)
{
	long	cheapest_price;
	t_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_price = LONG_MAX;
	while (b)
	{
		b->cheapest = false;
		if (b->cost < cheapest_price)
		{
			cheapest_price = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	price_calculator(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (same_half(b))
		{
			if (b->top_half)
				b->cost = find_higher(b->index, b->target->index);
			else
				b->cost = find_higher(size_b - b->index, size_a
						- b->target->index);
		}
		else
		{
			b->cost = (b->top_half) ? b->index : size_b - b->index;
			b->cost
				+= (b->target->top_half) ? b->target->index : size_a
				- b->target->index;
		}
		b = b->next;
	}
}

void	find_target(t_node *a, t_node *b)
{
	t_node	*aux;
	t_node	*target;
	long	closest_match;

	while (b)
	{
		closest_match = LONG_MAX;
		aux = a;
		while (aux)
		{
			if (aux->num > b->num && aux->num < closest_match)
			{
				target = aux;
				closest_match = aux->num;
			}
			aux = aux->next;
		}
		if (closest_match == LONG_MAX)
			b->target = find_lowest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	assign_index(t_node *node)
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

void	evaluate_nodes(t_node *a, t_node *b)
{
	assign_index(a);
	assign_index(b);
	find_target(a, b);
	price_calculator(a, b);
	flag_cheapest(b);
}
