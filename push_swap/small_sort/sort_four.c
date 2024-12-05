
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:14:09 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 14:03:54 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_four(t_node **stack_a, t_node **stack_b, char moves[], int i)
{
	int	j;

	j = ft_get_index(ft_get_min(*stack_a), *stack_a);
	i = ft_put_top_a(stack_a, j, moves, i);
	i = pb(stack_a, stack_b, moves, i);
	i = ft_sort_three(stack_a, moves, i);
	i = pa(stack_a, stack_b, moves, i);
	return (i);
}
