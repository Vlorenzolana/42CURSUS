/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:16:36 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/17 16:32:09 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
		if (tmp->ptr && tmp->del)
			tmp->del(tmp->ptr);
		free(tmp);
	}
	if (game->textures.north)
		mlx_delete_texture(game->textures.north);
	if (game->textures.south)
		mlx_delete_texture(game->textures.south);
	if (game->textures.west)
		mlx_delete_texture(game->textures.west);
	if (game->textures.east)
		mlx_delete_texture(game->textures.east);
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
/* 	if (game->sprite.frame1)
		mlx_delete_texture(game->sprite.frame1);
	if (game->sprite.frame2)
		mlx_delete_texture(game->sprite.frame2);
	if (game->sprite.frame3)
		mlx_delete_texture(game->sprite.frame3);
	if (game->sprite.frame4)
		mlx_delete_texture(game->sprite.frame4);
	if (game->spt)
		mlx_delete_image(game->mlx, game->spt); */