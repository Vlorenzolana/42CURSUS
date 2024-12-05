/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:27:42 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 15:05:48 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, int z)
{
	t_node	*current;
	int i;
	
	i = -1;
	current = stack;
	// If the stack is empty, print a message
	if (!current)
	{
		printf("Stack is empty.\n");
		return ; // no se retorna nada porque es un void
	}

	while (++i < z) // Iterate through the stack and print each node's content
	{
		printf("Stack A: %d\n", current->content);
		current = current->next;
	}
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;;
		free(stack);
		stack = tmp;
	}
}

// check repeat arg
bool	check_repeat(int *num)
{
	int	i;
	int	j;

	i = 0;
	while (num[i])
	{
		j = i + 1;
		while (num[j])
		{
			if (num[i] == num[j])
			{
				write(1, "Estoy aqui\n", 12);
				return (true); // Return early when a duplicate is found
			}
			j++;
		}
		i++;
	}
	return (false); // No duplicates found
}

int	check_arg(const char *str)
{
	long	num;
	int		i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-') // Allow optional leading sign
		i++;
	if (!str[i]) // Check if there's at least one digit after the sign
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i])) // Check for non-digit characters
			return (0);
		i++;
	}
	num = ft_atol(str); // Convert to long for range checking
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

// pasa los datos de char a integer
int	*ft_patoi(char *argv, int *patoi, int *z)
{
	char	**list_str;
	int	j;
	int	k;
	
	list_str = ft_split(argv, ' '); // Splitting the argument into substrings
	if (!list_str)
		return (NULL); // Pointer must return NULL
	j = 0;
	while (list_str[j])
		j++;
	patoi = (int *)malloc(j * sizeof(int));
	if (!patoi)
		return (ft_free(list_str), NULL);
	k = 0;
	z[0] = 0;
	while (k < j)
	{
		if (!check_arg(list_str[k])) // Validate the substring
		{
			write(1, "Error\n", 6);                       
				// write standard output STDOUT
			return (ft_free(list_str), free(patoi), NULL);
				// exit from function, not program!
		}
		patoi[k] = ft_atoi(list_str[k]);
		z[0]++; // count argumentos(int) porque uso int * patoi y no puede diferenciar un 0 del final del array '\0'
		printf("Converted integer: %d\n", patoi[k]);// Printing the converted values
		k++;
	}
	return (ft_free(list_str), patoi);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*patoi;
	
	int		i;
	int		j;
	int		z;

	stack_b = NULL;
	patoi = NULL;
	
	if (argc < 2 || ((argc == 2) && !argv[1]))
		return (1);
	i = 0;
	j = 0;
	z = 0;
	while (++i < argc) // Processing each argument with `ft_split`
	{
		patoi = ft_patoi(argv[i], patoi, &z);
		printf("num of nums: %i\n", z);
		if (!patoi)
			return (1);
		if (check_repeat(patoi)!= false) // C y las booleanas no se llevan bien
			return (write(1, "Error\n", 6), free(patoi), (1));
				j = -1;
		stack_a = ft_addfront(stack_a, patoi[0]); // Load each value into stack_a
	}
	//ordeno mi stack_a pequenito
	return (print_stack(stack_a, z), free_stack(stack_a), free(patoi), (0));
}
