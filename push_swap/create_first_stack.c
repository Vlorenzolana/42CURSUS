/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_first_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:44:43 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/29 09:45:40 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_node **a, char **argv, bool arg2)
{
	free_stack(a);
	if (arg2)
		free_str(argv);
	write(2, "Error\n", 6);
	exit(1);
}

t_node	*find_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	add_node(t_node **stack, int num)
{
	t_node	*new_node;
	t_node	*last;

	if (!stack)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = new_node;
		new_node->prev = last;
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

void	create_stack(t_node **a, char **argv, bool arg2)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i])
	{
		if (check_syntax_error(argv[i]))
			ft_error(a, argv, arg2);
		num = ft_atol(argv[i]);
		if (check_interval_error(num))
			ft_error(a, argv, arg2);
		if (check_repetition_error(*a, (int)num))
			ft_error(a, argv, arg2);
		add_node(a, (int)num);
		i++;
	}
}
