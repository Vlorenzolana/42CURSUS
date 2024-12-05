/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:52:47 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 14:25:08 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **stack)
{
	t_node	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = (*stack)->next;
	ft_lstlast(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

int	ra(t_node **stack_a, char moves[], int i)
{
	ft_rotate(stack_a);
	moves[i] = '6';
	i++;
	return (i);
}

int	rb(t_node **stack_b, char moves[], int i)
{
	ft_rotate(stack_b);
	moves[i] = '7';
	i++;
	return (i);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}