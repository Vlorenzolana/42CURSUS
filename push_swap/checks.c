/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:43:00 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/30 07:47:56 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**tidy_arg(char *argv)
{
	char	*aux;
	char	**prepared;

	aux = ft_strjoin("./push_swap ", argv);
	prepared = ft_split(aux, ' ');
	free(aux);
	aux = NULL;
	return (prepared);
}

bool	check_interval_error(long num)
{
	if (num < INT_MIN || INT_MAX < num)
		return (true);
	else
		return (false);
}

bool	check_syntax_error(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (true);
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (true);
		str++;
	}
	return (false);
}

bool	check_repetition_error(t_node *a, int nbr)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->num == nbr)
			return (true);
		a = a->next;
	}
	return (false);
}
