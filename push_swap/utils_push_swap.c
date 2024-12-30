/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:48:37 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/30 07:44:23 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	same_half(t_node *b)
{
	if (b->top_half == b->target->top_half)
		return (true);
	else
		return (false);
}

void	get_target(t_node *a, t_node *b)
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
			b->target = is_lowest(a);
		else
			b->target = target;
		b = b->next;
	}
}

int	get_higher(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

t_node	*get_cheapest(t_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	flag_cheapest(t_node *b)
{
	long	lowest_price;
	t_node	*cheapest_node;

	if (!b)
		return ;
	lowest_price = LONG_MAX;
	while (b)
	{
		b->cheapest = false;
		if (b->cost < lowest_price)
		{
			lowest_price = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}
