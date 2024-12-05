/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_stack_creation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:44:43 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 21:44:49 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the last node in a stack and returns a pointer to it. */
t_stack_node	*find_last_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

/* Add_node adds a new node to stack a after all checks have been successful.
First it allocates memory, then sets node->number, and then sets both node
pointers as corresponds. */
void	add_node(t_stack_node **stack, int number)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->number = number;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = (sign * -1);
			str++;
		}
		else
			str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

/* Create_stack performs all necessary checks (syntax, interval, and repetition)
to the argv and manages the initial stack a creation. If any check fails, then
error_free is called, allocated memory is freed and execution is interrupted. */
void	create_stack(t_stack_node **a, char **argv, bool argc_is_2)
{
	int		i;
	long	number;

	i = 1;
	while (argv[i])
	{
		if (check_syntax_error(argv[i]))
			error_free(a, argv, argc_is_2);
		number = ft_atol(argv[i]);
		if (check_interval_error(number))
			error_free(a, argv, argc_is_2);
		if (check_repetition_error(*a, (int)number))
			error_free(a, argv, argc_is_2);
		add_node(a, (int)number);
		i++;
	}
}