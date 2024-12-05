/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:45:40 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 21:45:42 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function to free allocated memory from a char string. */
void	free_argv(char **argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	argv = NULL;
}

/* Function to free allocated memory from a linked list aka stack. */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

/* Function to manage stack and/or string memory liberation as well as
displaying the required "Error" message. */
void	error_free(t_stack_node **a, char **argv, bool argc_is_2)
{
	free_stack(a);
	if (argc_is_2)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = prepare_argv(argv[1]);
	create_stack(&a, argv, argc == 2);
	if (argc == 2)
		free_argv(argv);
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			solve_for_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}