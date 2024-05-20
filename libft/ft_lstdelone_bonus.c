/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:32:30 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 09:44:34 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/* ft_lstdelone elimina un nodo de una lista enlazada y libera su memoria.
Primero, verifica si el nodo es NULL y, si no lo es, llama a la función del
para liberar la memoria del contenido del nodo.
Luego, utiliza free para liberar la memoria del nodo en sí. */