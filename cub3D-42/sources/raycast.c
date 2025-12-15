/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:13:36 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/14 18:25:16 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_refresh(t_ray *ray, t_player *p, int x)
{
	ray->camera = 2 * x / (double)WIN_W - 1;
	ray->ray_x = p->dir_x + p->plane_x * ray->camera;
	ray->ray_y = p->dir_y + p->plane_y * ray->camera;
	ray->map_x = (int)p->pos_x;
	ray->map_y = (int)p->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_x);
	ray->delta_dist_y = fabs(1 / ray->ray_y);
	ray->hit = 0;
}

void	ray_dir(t_ray *ray, t_player *player)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	check_hit(t_game *game)
{
	t_ray	*r;

	r = &game->raycast;
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side_hit = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side_hit = 1;
		}
		if (r->map_x < 0 || r->map_x >= game->map.map_w || r->map_y < 0
			|| r->map_y >= game->map.map_h)
			error_exit("Ray escaped map (map not closed)");
		if (game->map.map_array[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	set_dist(t_game *game)
{
	if (game->raycast.side_hit == 0)
	{
		game->raycast.wall_dist = ((game->raycast.map_x - game->player.pos_x
					+ (1 - game->raycast.step_x) / 2) / game->raycast.ray_x);
		game->raycast.wall_x = game->player.pos_y + game->raycast.wall_dist
			* game->raycast.ray_y;
	}
	else
	{
		game->raycast.wall_dist = ((game->raycast.map_y - game->player.pos_y
					+ (1 - game->raycast.step_y) / 2) / game->raycast.ray_y);
		game->raycast.wall_x = game->player.pos_x + game->raycast.wall_dist
			* game->raycast.ray_x;
	}
}

void	raycast(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		ray_refresh(&game->raycast, &game->player, x);
		ray_dir(&game->raycast, &game->player);
		check_hit(game);
		set_dist(game);
		draw_sky_and_floor(game, x);
		get_wall_height(game, x);
		x++;
	}
}
