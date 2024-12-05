/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:50:12 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 21:50:13 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates a stack so that the firs node is sent to the bottom of the stack.
Returns nothing; this is just pointer juggling. */
void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				size;

	size = stack_size(*stack);
	if (!stack || !*stack || size == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
}

/* Executes the RA command and writes "ra". */
void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/* Executes the RB command and writes "rb". */
void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/* Executes the RR command and writes "rr". */
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}