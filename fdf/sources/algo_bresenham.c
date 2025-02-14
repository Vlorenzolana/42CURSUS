/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:56:49 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/31 16:18:35 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_coordinate(int *x, int *y, t_point point)
{
	*x = (int)point.iso_scaled_x;
	*y = (int)point.iso_scaled_y;
}

void	draw_step(t_bresenham *b)
{
	int	error2;

	error2 = b->error * 2;
	if (error2 > -b->dy)
	{
		b->error -= b->dy;
		b->x0 += b->step_x;
	}
	if (error2 < b->dx)
	{
		b->error += b->dx;
		b->y0 += b->step_y;
	}
}

void	step_dir(int *step, int a, int b)
{
	if (a < b)
	{
		*step = 1;
	}
	else
		*step = -1;
}

void	algo_bresenham(t_bresenham *b, t_point origin, t_point target)
{
	get_coordinate(&b->x0, &b->y0, origin);
	get_coordinate(&b->x1, &b->y1, target);
	b->dx = abs(b->x1 - b->x0);
	b->dy = abs(b->y1 - b->y0);
	step_dir(&b->step_x, b->x0, b->x1);
	step_dir(&b->step_y, b->y0, b->y1);
	b->error = b->dx - b->dy;
}
