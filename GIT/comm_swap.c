/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:52:03 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/27 15:56:02 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*temp_first;
	t_node	*temp_second;

	if (!*stack || !stack || stack_size(*stack) == 1)
		return ;
	temp_first = *stack;
	temp_second = (*stack)->next;
	temp_first->prev = temp_second;
	temp_first->next = temp_second->next;
	temp_second->prev = NULL;
	temp_second->next = temp_first;
	if (temp_first->next)
		temp_first->next->prev = temp_first;
	*stack = temp_second;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
