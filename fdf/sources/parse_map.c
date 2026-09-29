/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:22:46 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/31 14:33:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_grid(t_point **grid, char *route_to_map, t_map *map)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		i;
	int		j;

	fd = open(route_to_map, O_RDONLY);
	i = 0;
	while (i < map->rows)
	{
		line = get_next_line(fd);
		split_line = ft_split(line, ' ');
		j = 0;
		while (line && split_line && j < map->cols)
		{
			grid[i][j].x = j;
			grid[i][j].y = i;
			grid[i][j].z = ft_atoi(split_line[j]);
			j++;
		}
		free(line);
		free_array(split_line);
		i++;
	}
	close(fd);
}

t_point	**alloc_grid(t_map *map)
{
	t_point	**grid;
	int		i;

	i = 0;
	grid = (t_point **)malloc(map->rows * sizeof(t_point *));
	if (grid == NULL)
		return (NULL);
	while (i < map->rows)
	{
		grid[i] = (t_point *)malloc(map->cols * sizeof(t_point));
		if (!grid[i])
		{
			free_grid(grid, i);
			print_error("Error allocating memory\n");
		}
		ft_bzero(grid[i], (map->cols * sizeof(t_point)));
		i++;
	}
	return (grid);
}

void	measure_map(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**split_line;

	i = 0;
	j = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (j == 0)
		{
			split_line = ft_split(line, ' ');
			while (split_line[j])
				j++;
			free_array(split_line);
		}
		free(line);
		i++;
	}
	map->rows = i;
	map->cols = j;
	close(fd);
}

t_point	**load_map(char *argv1, t_map *map)
{
	int		fd;
	char	*route_to_map;
	t_point	**grid;

	route_to_map = ft_strjoin("./maps/", argv1);
	fd = open(route_to_map, O_RDONLY);
	if (fd < 0)
	{
		free(route_to_map);
		print_error("Not possible to open map.\n");
	}
	measure_map(fd, map);
	grid = alloc_grid(map);
	close(fd);
	fill_grid(grid, route_to_map, map);
	free(route_to_map);
	map->point_cloud = map->rows * map->cols;
	map->grid = grid;
	return (grid);
}
