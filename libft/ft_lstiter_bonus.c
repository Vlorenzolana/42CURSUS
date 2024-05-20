/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:32:17 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 09:45:07 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

/* ft_lstiter permite iterar sobre una lista enlazada y aplicar una
función específica (f) a cada uno de los nodos de la lista.
Si la lista está vacía o no se proporciona una función para aplicar,
la función no realiza ninguna operación y simplemente retorna.
Si los argumentos son válidos, la función recorre la lista y aplica
f al contenido de cada nodo. */