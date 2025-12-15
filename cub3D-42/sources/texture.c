/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:36:47 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/14 19:13:44 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_color	px_tx(mlx_texture_t *texture, int x, int y)
{
	t_color	color;
	uint8_t	*pixel;

	color.red = 0;
	color.green = 0;
	color.blue = 0;
	color.alpha = 0;
	if (!texture)
		return (color);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= (int)texture->width)
		x = texture->width - 1;
	if (y >= (int)texture->height)
		y = texture->height - 1;
	pixel = texture->pixels + (y * texture->width + x)
		* texture->bytes_per_pixel;
	color.red = pixel[0];
	color.green = pixel[1];
	color.blue = pixel[2];
	color.alpha = pixel[3];
	return (color);
}

void	get_wall_texture(t_game *game)
{
	if (game->raycast.side_hit == 0)
	{
		if (game->raycast.ray_x > 0)
			game->wall_tex.tex = game->textures.east;
		else
			game->wall_tex.tex = game->textures.west;
	}
	else
	{
		if (game->raycast.ray_y > 0)
			game->wall_tex.tex = game->textures.south;
		else
			game->wall_tex.tex = game->textures.north;
	}
}

void	set_tex_params(t_wall_tex *wall_tex, t_ray *ray)
{
	if (wall_tex->tex->height == wall_tex->tex->width / 2)
		ray->wall_x /= 2;
	else if (wall_tex->tex->height == wall_tex->tex->width / 3)
		ray->wall_x /= 3;
	ray->wall_x -= floor(ray->wall_x);
	if (ray->side_hit == 0)
	{
		if (ray->step_x > 0)
			wall_tex->tex_x = (int)(ray->wall_x
					* (double)(wall_tex->tex->width));
		else
			wall_tex->tex_x = wall_tex->tex->width - (int)(ray->wall_x
					* (double)(wall_tex->tex->width)) - 1;
	}
	else
	{
		if (ray->step_y > 0)
			wall_tex->tex_x = wall_tex->tex->width - (int)(ray->wall_x
					* (double)(wall_tex->tex->width)) - 1;
		else
			wall_tex->tex_x = (int)(ray->wall_x
					* (double)(wall_tex->tex->width));
	}
}

void	get_wall_height(t_game *game, int x)
{
	int	line_h;
	int	wall_start;
	int	wall_end;

	line_h = (int)(WIN_H / game->raycast.wall_dist);
	wall_start = -line_h / 2 + WIN_H / 2;
	if (wall_start < 0)
		wall_start = 0;
	wall_end = line_h / 2 + WIN_H / 2;
	if (wall_end >= WIN_H)
		wall_end = WIN_H - 1;
	game->wall_tex.tex_step = 1.0 * (game->textures.north->height - 1) / line_h;
	game->wall_tex.tex_pos = (wall_start - WIN_H / 2 + line_h / 2)
		* game->wall_tex.tex_step;
	draw_stripe(game, x, wall_start, wall_end);
}
