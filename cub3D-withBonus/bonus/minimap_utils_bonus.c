/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:15:28 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/17 18:16:18 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MM_TILE)
	{
		j = 0;
		while (j < MM_TILE)
		{
			if (x + j >= 0 && x + j < WIN_W && y + i >= 0 && y + i < WIN_H)
				mlx_put_pixel(g->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

int	is_inside_map(t_game *g, int x, int y)
{
	if (y < 0 || y >= g->map.map_h)
		return (0);
	if (x < 0 || x >= g->map.map_w)
		return (0);
	return (1);
}

void	draw_minimap_tile(t_game *g, int i, int j)
{
	int		map_x;
	int		map_y;
	int		color;
	double	off_x;
	double	off_y;

	off_x = g->player.pos_x - MM_RADIUS;
	off_y = g->player.pos_y - MM_RADIUS;
	map_x = (int)(off_x + j);
	map_y = (int)(off_y + i);
	if (!is_inside_map(g, map_x, map_y))
		return ;
	if (g->map.map_array[map_y][map_x] == '1')
		color = 0xFFFFFFFF;
	else if (g->map.map_array[map_y][map_x] == '0')
		color = 0x333333FF;
	else
		return ;
	draw_square(g,
		MM_OFFSET_X + j * MM_TILE,
		MM_OFFSET_Y + i * MM_TILE,
		color);
}

void	draw_minimap_row(t_game *g, int i)
{
	int	j;

	j = 0;
	while (j < MM_SIZE)
	{
		draw_minimap_tile(g, i, j);
		j++;
	}
}
