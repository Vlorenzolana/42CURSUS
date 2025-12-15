/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:35:11 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/15 21:38:30 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_color_format(char **p)
{
	int	i;
	int	j;

	i = 0;
	while (p[i])
	{
		if (!p[i][0])
			error_exit("Invalid color format");
		j = 0;
		while (p[i][j])
		{
			if (!ft_isdigit(p[i][j]))
				error_exit("Invalid color digits");
			j++;
		}
		i++;
	}
	if (i != 3)
		error_exit("Invalid color format");
}

static void	put_rgb(int *rgb, t_color *c)
{
	c->red = rgb[0];
	c->green = rgb[1];
	c->blue = rgb[2];
	c->alpha = 255;
}

void	parse_color(t_color *c, char *s)
{
	char	**p;
	int		rgb[3];
	char	*clean;

	clean = ft_strtrim(s, " \t");
	if (!clean)
		error_exit("Color trim error");
	p = ft_split(clean, ',');
	free(clean);
	if (!p)
		error_exit("Color split error");
	check_color_format(p);
	rgb[0] = ft_atoi(p[0]);
	rgb[1] = ft_atoi(p[1]);
	rgb[2] = ft_atoi(p[2]);
	if (rgb[0] < 0 || rgb[0] > 255
		|| rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
	{
		free_split(p);
		error_exit("Color out of range");
	}
	gc_add(&g_game->gc, p, (void (*)(void *))free_split);
	put_rgb(rgb, c);
}
