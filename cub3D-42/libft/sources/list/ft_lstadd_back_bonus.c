/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:07:19 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (lst == NULL || new == NULL)
		return ;
	end = ft_lstlast(*lst);
	if (end)
		end -> next = new;
	else
		*lst = new;
}
/* int main()
{
	t_list *lista = NULL;
	t_list *n1;	
	t_list *n2;
	t_list *n3;

	n1 = ft_lstnew("B ");
	n2 = ft_lstnew("C ");
	n3 = ft_lstnew ("A ");
	ft_lstadd_back(&lista, n2);
	ft_lstadd_back(&lista, n1);
	ft_lstadd_back(&lista, n3);

	while (lista)
	{
		printf("%s\n", (char *)lista -> content);
		lista = lista -> next;
	}
	
	return 0;
} */