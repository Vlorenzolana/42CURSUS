/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:23:08 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/31 17:13:50 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso_coords(t_point *point)
{
	point->iso_x = (point->x - point->y) * cos(ISO_ANGLE);
	point->iso_y = (point->x + point->y) * sin(ISO_ANGLE) - point->z;
}

void	ft_scale_iso(t_point *point, t_map *map)
{
	point->iso_scaled_x = (point->iso_x * map->scale) + map->offset_x;
	point->iso_scaled_y = (point->iso_y * map->scale) + map->offset_y;
}

void	prepare_grid(t_point **grid, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			ft_iso_coords(&grid[i][j++]);
		}
		i++;
	}
	scale_and_offset(grid, map, 1920, 1080);
	map->initial_scale = map->scale;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			ft_scale_iso(&grid[i][j++], map);
		}
		i++;
	}
}
