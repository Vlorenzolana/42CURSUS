/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:33:28 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 12:47:05 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/* ft_lstlast recorre la lista enlazada desde el nodo inicial hasta llegar
al último nodo (donde lst->next es NULL) y devuelve un puntero a ese nodo.
Si la lista está vacía (es decir, lst es NULL), la función devuelve NULL
para indicar que no hay último nodo. */
/* int	main(void)
{
	t_list *n1 = ft_lstnew("Hola");
	t_list *n2 = ft_lstnew(" ");
	t_list *n3 = ft_lstnew("Mundo");

	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	printf("ultimo nodo: %s\n", (char *)ft_lstlast(n1)->content);
	return (0);
} */