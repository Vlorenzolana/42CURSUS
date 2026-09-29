/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:33:01 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 09:44:44 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* ft_lstadd_back agrega un nuevo nodo (new) al final de una lista enlazada.
Si la lista está vacía, el nuevo nodo se convierte en la cabeza de la lista.
Si la lista no está vacía, la función encuentra el último nodo y lo enlaza
con el nuevo nodo. */
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