/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:31:20 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 12:46:36 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

/* ft_lstnew crea un nuevo nodo para una lista enlazada, asigna el
contenido pasado como argumento a este nodo, inicializa su campo next a NULL
y devuelve el puntero al nuevo nodo.
Si la asignación de memoria falla, devuelve NULL. */
/* int main()
{
	int		*test_int = malloc (sizeof(int));

	*test_int = 50;
	t_list	*ejem_int = ft_lstnew(test_int);

	printf("%d\n",*((int *)ejem_int->content));


	char	test_str[] = "Hola Mundo";

	t_list	*ejem_str = ft_lstnew(test_str);

	printf("%s\n", (char *)ejem_str->content);

	return (0);
} */