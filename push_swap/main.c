/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:26:07 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 16:08:11 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, int z)
{
	t_node	*current;
	int		i;

	i = -1;
	current = stack;



	// If the stack is empty, print a message
	if (!current)
	{
		printf("Stack is empty.\n");
		return ;
	}

	// Iterate through the stack and print each node's content
	while (++i < z)
	{
		printf("Stack A: %d\n", current->content);
		current = current->next;
	}
}

void	free_stack(t_node *stack, int z)
{
	t_node	*tmp;

	while (z > 0)
	{
		tmp = stack->next;
		if(stack)
			free(stack);
		stack = tmp;
		z--;
	}
}

// Check for duplicate arguments
bool	check_repeat(int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (num[i] == num[j])
			{
				write(1, "Estoy aqui\n", 12);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

int	check_arg(const char *str)
{
	long	num;
	int		i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i]) // Check if there's at least one digit after the sign
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atol(str); // Convert to long for range checking
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

// Convert char to integer and validate arguments
int	*ft_patoi(char *argv, int *patoi, int *z)
{
	int		*temp;
	int		j;
	int		k;

	j = 0;
	while (list_str[j])
		j++;
	temp = (int *)malloc(j * sizeof(int)); // Allocate memory for integer array
	if (!temp)
		return (ft_free(list_str), NULL);

	k = 0;
	z[0] = 0;
	while (k < j)
	{
		if (!check_arg(list_str[k])) //Validate each substring
		{
			write(1, "Error\n", 6);
			return (ft_free(list_str), free(temp), NULL);
		}
		temp[k] = ft_atoi(list_str[k]);
		++z[0]; // Count the arguments
		printf("Converted integer: %d\n", temp[k]); //Print the converted values
		k++;
	}
	return (ft_free(list_str), temp); //Free the split strings and return temp
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char ** list_str;
	int		*patoi;
	int		*old_patoi;
	int		i;
	int		z;

	stack_a = NULL;
	stack_b = NULL;
	patoi = NULL;
	old_patoi = NULL;

	if (argc < 2 || ((argc == 2) && !argv[1]))
		return (1);

	i = 0;
	z = 0;
	
	list_str = ft_split(argv, ' '); // Split the argument into substrings
	if (!list_str)
		return (NULL); // Return NULL on failure

	while (++i < argc) // Process each argument with `ft_split`
	{
		old_patoi = patoi;               // Keep track of the previous pointer
		patoi = ft_patoi(argv[i], patoi, &z);
		printf("Print z %d\n", z);
	
		if (old_patoi)
			free(old_patoi);             // Free the old memory

		if (!patoi)                      // Handle errors
			return (1);
		if (check_repeat(patoi, z))      // Check for duplicates
			return (write(1, "Error\n", 6), free(patoi), (1));

		stack_a = ft_addfront(stack_a, patoi[0]); // Add value to stack_a
	}

	// Print and free resources
	print_stack(stack_a, z);
	free_stack(stack_a, z);
	free(patoi);
	return (0);
}

/* 

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
		free(patoi);
	}
	//ordeno mi stack_a pequenito
	return (print_stack(stack_a, z), free_stack(stack_a), free(patoi), (0));
}
 */