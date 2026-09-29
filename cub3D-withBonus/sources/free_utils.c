/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:54:02 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/16 14:50:50 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	gc_cleanup(void)
{
	t_gc_node	*tmp;

	if (!g_game)
		return ;
	while (g_game->gc.head)
	{
		tmp = g_game->gc.head;
		g_game->gc.head = tmp->next;
		if (tmp->ptr && tmp->del)
			tmp->del(tmp->ptr);
		free(tmp);
	}
}

void	error_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	gc_cleanup();
	exit(EXIT_FAILURE);
}
