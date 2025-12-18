/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:19:15 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst -> next;
	}
	return (lst);
}

/* int main()
{
	t_list	*n1 = ft_lstnew("Hola");
	t_list	*n2 = ft_lstnew(" ");
	t_list	*n3 = ft_lstnew("Mundo");

	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = NULL;
	
	printf("ultimo nodo: %s\n", (char *)ft_lstlast(n1) -> content);
	return 0;
} */