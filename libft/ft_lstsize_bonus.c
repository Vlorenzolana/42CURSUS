/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:31:02 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 09:45:55 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
/* ft_lstsize calcula y devuelve el número de nodos en una lista enlazada.
Recorre la lista desde la cabeza hasta el final, contando cada nodo
que encuentra, y luego devuelve el contador. */
/* 
int	main(void)
{
	t_list	*n1 = ft_lstnew("Hola");
	t_list	*n2 = ft_lstnew(" ");
	t_list	*n3 = ft_lstnew("como");
	t_list	*n4 = ft_lstnew(" ");
	t_list	*n5 = ft_lstnew("estás");
	int		len;

	n1 -> next = n2; 
	n2 -> next = n3; 
	n3 -> next = n4; 
	n4 -> next = n5; 
	n5 -> next = NULL;
	len = ft_lstsize(n1);

	printf("cantidad de nodos: %d\n", len);
	return 0;
} */