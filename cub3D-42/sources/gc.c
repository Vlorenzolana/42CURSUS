/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:30:25 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/15 21:24:06 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	gc_init(t_gc *gc)
{
	gc->head = NULL;
}

void	gc_add(t_gc *gc, void *ptr, void (*del)(void *))
{
	t_gc_node	*node;

	if (!ptr || !del)
		return ;
	node = malloc(sizeof(t_gc_node));
	if (!node)
		error_exit("GC malloc failed");
	node->ptr = ptr;
	node->del = del;
	node->next = gc->head;
	gc->head = node;
}

void	game_clear(t_game *game)
{
	t_gc_node	*tmp;

	while (game->gc.head)
	{
		tmp = game->gc.head;
		game->gc.head = tmp->next;
		if (tmp->ptr)
		{
			tmp->del(tmp->ptr);
			tmp->ptr = NULL;
		}
		if (tmp)
		{
			tmp->del(tmp);
			tmp = NULL;
		}
	}
	mlx_delete_texture(game->textures.north);
	mlx_delete_texture(game->textures.south);
	mlx_delete_texture(game->textures.west);
	mlx_delete_texture(game->textures.east);
}
