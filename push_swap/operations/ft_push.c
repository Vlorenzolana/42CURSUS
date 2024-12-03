/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:27:39 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/11/07 17:43:44 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **stack_get, t_node **stack_give)
{
	t_node	*temp;

	if (!(*stack_give))
		return ;
	temp = (*stack_give)->next;
	(*stack_give)->next = *stack_get;
	*stack_get = *stack_give;
	*stack_give = temp;
}

int	pa(t_node **stack_a, t_node **stack_b, char moves[], int i)
{
	ft_push(stack_a, stack_b);
	moves[i] = '4';
	i++;
	return (i);
}

int	pb(t_node **stack_a, t_node **stack_b, char moves[], int i)
{
	ft_push(stack_b, stack_a);
	moves[i] = '5';
	i++;
	return (i);
}