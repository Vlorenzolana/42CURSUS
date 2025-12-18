/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:16:27 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/16 17:16:29 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
