/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:11:27 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/16 13:55:44 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	max_width(char **m)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (m[i] && !is_empty_line(m[i]))
	{
		len = ft_strlen(m[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

char	*pad(char *row, int w)
{
	int		len;
	char	*r;

	len = ft_strlen(row);
	r = malloc(w + 1);
	if (!r)
		error_exit("pad malloc");
	ft_memcpy(r, row, len);
	ft_memset(r + len, ' ', w - len);
	r[w] = '\0';
	return (r);
}

int	count_map_lines(char **m)
{
	int	count;

	count = 0;
	while (m[count] && !is_empty_line(m[count]))
		count++;
	if (count == 0)
		error_exit("Error: Empty map");
	return (count);
}

void	load_map_parser(t_parser *p, char **lines)
{
	int	i;
	int	width;

	p->map_h = 0;
	while (lines[p->map_h])
		p->map_h++;
	width = max_width(lines);
	p->map = malloc(sizeof(char *) * (p->map_h + 1));
	if (!p->map)
		error_exit("Malloc failed loading map");
	gc_add(&g_game->gc, p->map, (void (*)(void *))free_split);
	i = 0;
	while (i < p->map_h)
	{
		p->map[i] = pad(lines[i], width);
		if (!p->map[i])
			error_exit("Malloc failed duplicating map");
		i++;
	}
	p->map[i] = NULL;
	p->map_w = width;
}
