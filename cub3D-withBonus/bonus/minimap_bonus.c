/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:36:41 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/17 18:16:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_minimap(t_game *g)
{
	int	i;

	i = 0;
	while (i < MM_SIZE)
	{
		draw_minimap_row(g, i);
		i++;
	}
}

void	draw_minimap_player(t_game *g)
{
	int	cx;
	int	cy;
	int	i;
	int	j;

	cx = MM_OFFSET_X + MM_CENTER;
	cy = MM_OFFSET_Y + MM_CENTER;
	i = -3;
	while (i <= 3)
	{
		j = -3;
		while (j <= 3)
		{
			mlx_put_pixel(g->img, cx + j, cy + i, 0xFF0000FF);
			j++;
		}
		i++;
	}
}

void	draw_minimap_dir(t_game *g)
{
	int	cx;
	int	cy;
	int	i;

	cx = MM_OFFSET_X + MM_CENTER;
	cy = MM_OFFSET_Y + MM_CENTER;
	i = 0;
	while (i < 15)
	{
		mlx_put_pixel(g->img, cx + (int)(g->player.dir_x * i),
			cy + (int)(g->player.dir_y * i),
			0x00FF00FF);
		i++;
	}
}
