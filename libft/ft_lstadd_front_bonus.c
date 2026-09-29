/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:32:54 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 12:47:59 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/* 
ft_lstadd_front agrega un nuevo nodo (new) al principio de una
lista enlazada. Si new es NULL, la función no realiza ninguna operación.
Si lst es NULL, la función convierte new en la cabeza de la lista.
En general, la función establece el campo next del nuevo nodo para que
apunte a la cabeza actual de la lista, y luego actualiza *lst para que
apunte al nuevo nodo, convirtiéndolo en la nueva cabeza de la lista.
 *//* 
int main()
{
	t_list *lista = ft_lstnew("W ");
	t_list *n1;	
	t_list *n2;
	t_list *n3;
	
	n1 = ft_lstnew("A ");
	n2 = ft_lstnew("B ");
	n3 = ft_lstnew ("C ");
	ft_lstadd_front(&lista, n1);//el & de un * es doble **
	ft_lstadd_front(&lista, n2);
	ft_lstadd_front(&lista, n3);

	while (lista)
	{
		printf("%s\n", (char *)(lista -> content));
		lista = lista -> next;
	}
	return 0;
} */