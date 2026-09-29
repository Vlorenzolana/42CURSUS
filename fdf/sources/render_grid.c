/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:23:06 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/31 17:13:29 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	grid_overflow(t_point *point)
{
	if (point->iso_scaled_x < 0 || point->iso_scaled_x >= 1920
		|| point->iso_scaled_y < 0 || point->iso_scaled_y >= 1080)
	{
		return (1);
	}
	return (0);
}

void	calculate_iso_bounds(t_point **grid, t_map *map)
{
	int	i;
	int	j;

	map->min_x = grid[0][0].iso_x;
	map->max_x = grid[0][0].iso_x;
	map->min_y = grid[0][0].iso_y;
	map->max_y = grid[0][0].iso_y;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (grid[i][j].iso_x < map->min_x)
				map->min_x = grid[i][j].iso_x;
			if (grid[i][j].iso_x > map->max_x)
				map->max_x = grid[i][j].iso_x;
			if (grid[i][j].iso_y < map->min_y)
				map->min_y = grid[i][j].iso_y;
			if (grid[i][j].iso_y > map->max_y)
				map->max_y = grid[i][j].iso_y;
			j++;
		}
		i++;
	}
}

void	scale_and_offset(t_point **grid, t_map *map, int w_width, int w_height)
{
	double	iso_width;
	double	iso_height;

	calculate_iso_bounds(grid, map);
	iso_width = map->max_x - map->min_x;
	iso_height = map->max_y - map->min_y;
	if (w_width / iso_width < w_height / iso_height)
		map->scale = w_width / iso_width;
	else
	{
		map->scale = w_height / iso_height;
	}
	map->offset_x = (w_width - iso_width * map->scale) / 2 - (map->min_x
			* map->scale);
	map->offset_y = (w_height - iso_height * map->scale) / 2 - (map->min_y
			* map->scale);
}

void	render_grid(mlx_image_t *img, t_point **grid, t_map *map)
{
	int		i;
	int		j;
	double	x2d;
	double	y1d;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			x2d = grid[i][j].iso_scaled_x;
			y1d = grid[i][j].iso_scaled_y;
			if (!grid_overflow(&grid[i][j]))
			{
				mlx_put_pixel(img, (uint32_t)x2d, (uint32_t)y1d, 0xFFFFFFFF);
			}
			j++;
		}
		i++;
	}
}
