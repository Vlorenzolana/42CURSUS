/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:45:40 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/28 10:40:16 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **argv)
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

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = prepare_argv(argv[1]);
	create_stack(&a, argv, argc == 2);
	if (argc == 2)
		free_str(argv);
	if (!sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
/* TEST EVALUATION:
//with ""
./push_swap "9 99 88 8 77 7 66 6 55 5 44 4 33 3 22 2 11 1 
9999 8888 7777 6666 5555 4444 3333 2222 1111 999 888 777 
666 555 444 333 222 111 99999 88888 77777 66666 55555 44444 
33333 22222 11111 999999 888888 777777 666666 555555 444444 
333333 222222 111111"

//without ""
./push_swap 9 99 88 8 77 7 66 6 55 5 44 4 33 3 22 2 11 1 
9999 8888 7777 6666 5555 4444 3333 2222 1111 999 888 777 
666 555 444 333 222 111 99999 88888 77777 66666 55555 44444 
33333 22222 11111 999999 888888 777777 666666 555555 444444 
333333 222222 111111

ARG="9 99 88 8 77 7 66 6 55 5 44 4 33 3 22 2 11 1 9999 
8888 7777 6666 5555 4444 3333 2222 1111 999 888 777 
666 555 444 333 222 111 99999 88888 77777 66666 55555
44444 33333 22222 11111 999999 888888 777777 666666 555555
444444 333333 222222 111111"; ./push_swap $ARG | tee >(wc -l)
 | ./checker_linux $ARG
*/

/*
Verify Permissions:
You can verify that the permissions are correct by running:

ls -l checker_linux
chmod 777 checker_linux

Re-run your original command:

./push_swap $ARG | tee >(wc -l) | ./checker_linux $ARG
*/