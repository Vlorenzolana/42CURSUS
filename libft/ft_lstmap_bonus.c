/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:12:08 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 12:45:15 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*element;
	void	*e;

	new_list = NULL;
	if (lst == NULL)
		return (new_list);
	while (lst != NULL)
	{
		e = f(lst->content);
		element = ft_lstnew(e);
		if (element == NULL)
		{
			free(e);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, element);
		lst = lst->next;
	}
	return (new_list);
}

/* ft_lstmap crea una nueva lista a partir de una lista original,
aplicando una función (f) a cada nodo para obtener el contenido de
los nuevos nodos. Si ocurre un error durante el proceso, libera cualquier
memoria asignada y retorna NULL. Si todo funciona correctamente,
retorna la nueva lista. */