/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:44 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/17 18:27:51 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error_exit("Invalid color digits");
		i++;
	}
}

static int	count_parts(char **p)
{
	int	count;

	count = 0;
	while (p && p[count])
		count++;
	return (count);
}

static void	parse_rgb_parts(char **p, int *rgb)
{
	if (!p[0][0] || !p[1][0] || !p[2][0])
		error_exit("Color format error: empty value");
	check_digits(p[0]);
	check_digits(p[1]);
	check_digits(p[2]);
	rgb[0] = ft_atoi(p[0]);
	rgb[1] = ft_atoi(p[1]);
	rgb[2] = ft_atoi(p[2]);
	if (rgb[0] < 0 || rgb[0] > 255
		|| rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		error_exit("Color out of range");
}

void	parse_color(t_color *c, char *s)
{
	char	**p;
	char	*trimmed;
	int		rgb[3];

	trimmed = ft_strtrim(s, " \t\n");
	if (!trimmed || !*trimmed)
		error_exit("Color format error: empty color string");
	gc_add(&g_game->gc, trimmed, free);
	p = ft_split(trimmed, ',');
	if (!p || count_parts(p) != 3)
	{
		free_split(p);
		error_exit("Color format error: expected R,G,B");
	}
	gc_add(&g_game->gc, p, (void (*)(void *))free_split);
	parse_rgb_parts(p, rgb);
	c->red = rgb[0];
	c->green = rgb[1];
	c->blue = rgb[2];
	c->alpha = 255;
}
