/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:16:12 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/16 17:16:14 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_sky_and_floor(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		mlx_put_pixel(game->img, x, y, game->textures.ceiling_color);
		y++;
	}
	while (y < WIN_H)
	{
		mlx_put_pixel(game->img, x, y, game->textures.floor_color);
		y++;
	}
}

int	dim_color(t_color *color, double dist)
{
	int	new_color;

	dist /= 3;
	if (dist < 1)
		dist = 1;
	color->red /= dist;
	color->green /= dist;
	color->blue /= dist;
	new_color = get_rgba(color->red, color->green, color->blue, color->alpha);
	return (new_color);
}

void	draw_empty_stripe(t_game *game, int x, int start, int end)
{
	int	y;

	y = start;
	while (y <= end)
	{
		mlx_put_pixel(game->img, x, y, game->textures.floor_color);
		y++;
	}
}

void	textured_stripe(t_game *game, int x, int start, int end)
{
	int		y;
	int		dimmed;
	t_color	color;

	y = start;
	while (y <= end)
	{
		game->wall_tex.tex_y = ((int)game->wall_tex.tex_pos)
			% game->wall_tex.tex->height;
		game->wall_tex.tex_pos += game->wall_tex.tex_step;
		color = px_tx(game->wall_tex.tex, game->wall_tex.tex_x,
				game->wall_tex.tex_y);
		dimmed = dim_color(&color, game->raycast.wall_dist);
		mlx_put_pixel(game->img, x, y, dimmed);
		y++;
	}
}

void	draw_stripe(t_game *game, int x, int start, int end)
{
	get_wall_texture(game);
	if (!game->wall_tex.tex)
	{
		draw_empty_stripe(game, x, start, end);
		return ;
	}
	set_tex_params(&game->wall_tex, &game->raycast);
	textured_stripe(game, x, start, end);
}
