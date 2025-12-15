/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:11:27 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/15 21:24:58 by vlorenzo         ###   ########.fr       */
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

	p->map_h = 0;
	while (lines[p->map_h])
		p->map_h++;
	p->map = malloc(sizeof(char *) * (p->map_h + 1));
	if (!p->map)
		error_exit("Malloc failed loading map");
	gc_add(&g_game->gc, p->map, (void (*)(void *))free_split);
	i = 0;
	while (i < p->map_h)
	{
		p->map[i] = ft_strdup(lines[i]);
		if (!p->map[i])
			error_exit("Malloc failed duplicating map");
		i++;
	}
	p->map[i] = NULL;
	p->map_w = 0;
	i = 0;
	while (i < p->map_h)
	{
		if ((int)ft_strlen(p->map[i]) > p->map_w)
			p->map_w = ft_strlen(p->map[i++]);
	}
}
