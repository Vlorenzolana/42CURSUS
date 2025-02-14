/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:22:59 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/02/03 17:57:01 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(mlx_image_t *img, t_point origin, t_point target, uint32_t color)
{
	t_bresenham	b;

	ft_bzero(&b, sizeof(t_bresenham));
	algo_bresenham(&b, origin, target);
	while (true)
	{
		mlx_put_pixel(img, b.x0, b.y0, color);
		if (b.x0 == b.x1 && b.y0 == b.y1)
		{	
			break ;
		}
		draw_step(&b);
	}
}

void	render_lines(mlx_image_t *img, t_point **grid, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (j < map->cols - 1)
			{
				if (!grid_overflow(&grid[i][j]) && !grid_overflow(&grid[i][j
						+ 1]))
					draw(img, grid[i][j], grid[i][j + 1], 0xFFCCCBFF);
			}
			if (i < map->rows - 1)
			{
				if (!grid_overflow(&grid[i][j]) && !grid_overflow(&grid[i
						+ 1][j]))
					draw(img, grid[i][j], grid[i + 1][j], 0xFFD9E6FF);
			}
			j++;
		}
		i++;
	}
}
