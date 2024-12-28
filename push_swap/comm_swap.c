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

/* Swaps the two first nodes of a stack. Just pointer games with no return. */
void	swap(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (!*stack || !stack || stack_size(*stack) == 1)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	second_node->prev = NULL;
	second_node->next = first_node;
	if (first_node->next)
		first_node->next->prev = first_node;
	*stack = second_node;
}

/* Executes the SA command and writes "sa". */
void	sa(t_stack_node	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/* Executes the SB command and writes "sb". */
void	sb(t_stack_node	**b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/* Executes the SA and SB commands and writes "sa". */
void	ss(t_stack_node	**a, t_stack_node	**b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
