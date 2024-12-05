/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:14:09 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 14:25:08 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_node **stack_a, char moves[], int i)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if ((first > second) && (second < third) && (first < third))
		i = sa(*stack_a, moves, i);
	else if ((first > second) && (second > third) && (first > third))
	{
		i = sa(*stack_a, moves, i);
		i = rra(stack_a, moves, i);
	}
	else if ((first > second) && (second < third) && (first > third))
		i = ra(stack_a, moves, i);
	else if ((first < second) && (second > third) && (first < third))
	{
		i = sa(*stack_a, moves, i);
		i = ra(stack_a, moves, i);
	}	
	else if ((first < second) && (second > third) && (first > third))
		i = rra(stack_a, moves, i);
	return (i);
}
