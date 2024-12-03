/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:51:06 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/11/07 18:51:49 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *stack)
{
	int	temp;

	if (!(stack) || !(stack->next))
		return ;
	temp = (stack->content);
	stack->content = stack->next->content;
	stack->next->content = temp;
}

int	sa(t_node *stack_a, char moves[], int i)
{
	ft_swap(stack_a);
	moves[i] = '1';
	i++;
	return (i);
}

int	sb(t_node *stack_b, char moves[], int i)
{
	ft_swap(stack_b);
	moves[i] = '2';
	i++;
	return (i);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}