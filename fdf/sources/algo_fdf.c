/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:57:17 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/31 17:03:24 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	algo_fdf(t_point **grid, t_map *map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	(void)grid;
	(void)map;
	(void)img;
	mlx = mlx_init(1920, 1080, "fdf", true);
	img = mlx_new_image(mlx, 1920, 1080);
	prepare_grid(grid, map);
	map->grid = grid;
	map->img = img;
	map->mlx = mlx;
	map->angle = 0;
	render_grid(img, grid, map);
	render_lines(img, grid, map);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, hook_handle, map);
	mlx_loop(mlx);
	free_grid(grid, map->rows);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
