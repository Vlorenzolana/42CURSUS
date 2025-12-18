/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:16:55 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/15 21:40:46 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_color_line(t_color *c, char *line, char *err)
{
	if (c->red != -1)
		error_exit(err);
	parse_color(c, line);
}

void	parse_texture(t_parser *p, char *err, char **dst, char *line)
{
	char	*trimmed;

	(void)p;
	if (*dst)
		error_exit(err);
	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed || !*trimmed)
		error_exit("Invalid texture path");
	*dst = trimmed;
	gc_add(&g_game->gc, trimmed, free);
}

void	parse_ident_line(t_parser *p, char *l)
{
	if (!ft_strncmp(l, "NO ", 3))
		parse_texture(p, "Error: Duplicate NO texture", &p->paths.no, l + 3);
	else if (!ft_strncmp(l, "SO ", 3))
		parse_texture(p, "Error: Duplicate SO texture", &p->paths.so, l + 3);
	else if (!ft_strncmp(l, "WE ", 3))
		parse_texture(p, "Error: Duplicate WE texture", &p->paths.we, l + 3);
	else if (!ft_strncmp(l, "EA ", 3))
		parse_texture(p, "Error: Duplicate EA texture", &p->paths.ea, l + 3);
	else if (!ft_strncmp(l, "F ", 2))
		parse_color_line(&p->floor_color, l + 2, "Error: Duplicate F color");
	else if (!ft_strncmp(l, "C ", 2))
		parse_color_line(&p->ceil_color, l + 2, "Error: Duplicate C color");
}

mlx_texture_t	*load_png_strict(char *path)
{
	mlx_texture_t	*t;

	if (!path)
		return (NULL);
	if (access(path, R_OK) != 0)
	{
		fprintf(stderr, "Texture not accessible: %s\n", path);
		return (NULL);
	}
	t = mlx_load_png(path);
	if (!t)
		fprintf(stderr, "mlx_load_png failed for: %s\n", path);
	return (t);
}

void	load_textures_from_parser(t_game *game, t_parser *p)
{
	if (!game || !p)
		error_exit("load_textures_from_parser: invalid args");
	game->textures.north = load_png_strict(p->paths.no);
	game->textures.south = load_png_strict(p->paths.so);
	game->textures.west = load_png_strict(p->paths.we);
	game->textures.east = load_png_strict(p->paths.ea);
	game->textures.floor_color = get_rgba(p->floor_color.red,
			p->floor_color.green, p->floor_color.blue, p->floor_color.alpha);
	game->textures.ceiling_color = get_rgba(p->ceil_color.red,
			p->ceil_color.green, p->ceil_color.blue, p->ceil_color.alpha);
	if (!game->textures.north || !game->textures.south || !game->textures.west
		|| !game->textures.east)
	{
		if (game->textures.north)
			mlx_delete_texture(game->textures.north);
		if (game->textures.south)
			mlx_delete_texture(game->textures.south);
		if (game->textures.west)
			mlx_delete_texture(game->textures.west);
		if (game->textures.east)
			mlx_delete_texture(game->textures.east);
		error_exit("One or more textures failed to load");
	}
}
