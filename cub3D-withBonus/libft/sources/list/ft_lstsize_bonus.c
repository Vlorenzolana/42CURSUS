/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:15:51 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
/* 
int main()
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
}
 */