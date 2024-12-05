/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:43:00 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 21:43:02 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Here the argv is prepared and split in the special case argv == 2.  */
char	**prepare_argv(char *argv)
{
	char	*aux;
	char	**prepared;

	aux = ft_strjoin("./push_swap ", argv);
	prepared = ft_split(aux, ' ');
	free(aux);
	aux = NULL;
	return (prepared);
}

/* Check_interval checks whether number is inside the int range. 
Returns true if outside of range. */
bool	check_interval_error(long number)
{
	if (number < INT_MIN || INT_MAX < number)
	{
		return (true);
	}
	else
		return (false);
}

/* Check_syntax_error checks that argv[i] is valid, e.g. one '+' or '-'
and only numeric characters. Returns true if any error is found. */
bool	check_syntax_error(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	if (!*str)
	{
		return (true);
	}
	while (*str)
	{
		if (*str < '0' || '9' < *str)
		{
			return (true);
		}
		str++;
	}
	return (false);
}

/* Check_repetition checks that the new number to be added to the stack
is not already present in it. Returns true if already present. */
bool	check_repetition_error(t_stack_node *a, int nbr)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->number == nbr)
			return (true);
		a = a->next;
	}
	return (false);
}