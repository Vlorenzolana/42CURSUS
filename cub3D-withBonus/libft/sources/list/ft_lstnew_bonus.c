/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:39:04 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (node == NULL)
	{
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int main()
{
	int		*test_int = malloc (sizeof(int));

	*test_int = 50;
	t_list	*ejem_int = ft_lstnew(test_int);

	printf("%d\n",*((int *)ejem_int->content));

	
	char	test_str[] = "Hola Mundo";

	t_list	*ejem_str = ft_lstnew(test_str);

	printf("%s\n", (char *)ejem_str->content);
	return 0;
} */