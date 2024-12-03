/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:13:41 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/11/07 19:13:53 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max(t_node *lst)
{
	int	max;

	if (!lst)
		return (-1);
	max = lst->content;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}	
	return (max);
}

int	ft_get_min(t_node *lst)
{
	int	min;

	if (!lst)
		return (-1);
	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}	
	return (min);
}

int	ft_get_index(int nb, t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == nb)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

int	ft_lstsize(t_node *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}