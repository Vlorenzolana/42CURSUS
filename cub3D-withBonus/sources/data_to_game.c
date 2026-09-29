/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:34:57 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/15 18:18:45 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	copy_map(t_parser *p, t_game *g)
{
	int	i;

	g->map.map_array = malloc(sizeof(char *) * (p->map_h + 1));
	if (!g->map.map_array)
		error_exit("Malloc failed in copy_map");
	gc_add(&g->gc, g->map.map_array,
		(void (*)(void *))free_split);
	i = 0;
	while (i < p->map_h)
	{
		g->map.map_array[i] = ft_strdup(p->map[i]);
		if (!g->map.map_array[i])
			error_exit("Malloc failed duplicating map row");
		i++;
	}
	g->map.map_array[i] = NULL;
}

void	set_player_dir(t_game *g, char dir)
{
	if (dir == 'N')
	{
		g->player.dir_x = 0;
		g->player.dir_y = -1;
	}
	else if (dir == 'S')
	{
		g->player.dir_x = 0;
		g->player.dir_y = 1;
	}
	else if (dir == 'W')
	{
		g->player.dir_x = -1;
		g->player.dir_y = 0;
	}
	else if (dir == 'E')
	{
		g->player.dir_x = 1;
		g->player.dir_y = 0;
	}
}

void	set_player_plane(t_game *g, char dir)
{
	if (dir == 'N')
	{
		g->player.plane_x = 0.66;
		g->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		g->player.plane_x = -0.66;
		g->player.plane_y = 0;
	}
	else if (dir == 'W')
	{
		g->player.plane_x = 0;
		g->player.plane_y = -0.66;
	}
	else if (dir == 'E')
	{
		g->player.plane_x = 0;
		g->player.plane_y = 0.66;
	}
}

void	data_to_game(t_parser *p, t_game *g)
{
	if (!p || !g)
		error_exit("Parser or game not initialized");
	g->map.map_h = p->map_h;
	g->map.map_w = p->map_w;
	copy_map(p, g);
	g->player.pos_x = p->player_y + 0.5;
	g->player.pos_y = p->player_x + 0.5;
	set_player_dir(g, p->player_dir);
	set_player_plane(g, p->player_dir);
	g->player.speed = 0.12;
	g->player.rotate_speed = 0.08;
}
