/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_rev_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:49:38 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/27 15:56:02 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Reverse rotates the stack so that the bottom node is sent to the top. */
void	reverse_rotate(t_node **stack)
{
	t_node	*last_node;
	int				size;

	size = stack_size(*stack);
	if (!stack || !*stack || size == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	last_node->prev = NULL;
	*stack = last_node;
}

/* Executes the RRA command and writes "rra". */
void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/* Executes the RRB command and writes "rrb". */
void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/* Executes the RRR command and writes "rrr". */
void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}