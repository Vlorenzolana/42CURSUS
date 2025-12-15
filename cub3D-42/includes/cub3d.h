/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:23:33 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/15 21:56:25 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"

/* ================================ DEFINES ================================= */
# define WIN_W 1366
# define WIN_H 768
# define TILE 10

/* ================================ GLOBAL ================================== */
typedef struct s_game	t_game;
extern t_game			*g_game;

/* =========================== GARBAGE COLLECTOR ============================ */
typedef struct s_gc_node
{
	void				*ptr;
	void				(*del)(void *);
	struct s_gc_node	*next;
}	t_gc_node;

typedef struct s_gc
{
	t_gc_node	*head;
}	t_gc;

/* =============================== COLORS ================================== */
typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	alpha;
}	t_color;

/* =============================== PLAYER ================================== */
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	speed;
	double	rotate_speed;
}	t_player;

/* ================================ MAP ==================================== */
typedef struct s_map
{
	char	**map_array;
	int		map_w;
	int		map_h;
}	t_map;

/* ============================== TEXTURES ================================= */
typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	int				floor_color;
	int				ceiling_color;
}	t_texture;

/* ============================== WALL TEX ================================= */
typedef struct s_wall_tex
{
	mlx_texture_t	*tex;
	int				tex_x;
	int				tex_y;
	double			tex_pos;
	double			tex_step;
}	t_wall_tex;

/* ================================ RAY ==================================== */
typedef struct s_ray
{
	double	camera;
	double	ray_x;
	double	ray_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	double	wall_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side_hit;
}	t_ray;

/* ================================ PATHS ================================== */
typedef struct s_paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_paths;

/* =============================== PARSER ================================== */
typedef struct s_parser
{
	t_paths	paths;
	t_color	floor_color;
	t_color	ceil_color;
	char	**map;
	int		map_w;
	int		map_h;
	int		player_x;
	int		player_y;
	char	player_dir;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_parser;

/* ================================ GAME =================================== */
typedef struct s_game
{
	void		*mlx;
	void		*img;
	t_map		map;
	t_player	player;
	t_texture	textures;
	t_ray		raycast;
	t_wall_tex	wall_tex;
	t_gc		gc;
}	t_game;

//	GARBAGE COLLECTOR ==================================================
void			gc_init(t_gc *gc);
void			gc_add(t_gc *gc, void *ptr, void (*del)(void *));
void			game_clear(t_game *game);

// CHECK_UTILS =========================================================
int				check_args(int argc, char **argv);
void			locate_player(t_parser *p);
void			flood(char **m, int x, int y, t_parser *p);
void			check_borders(t_parser *p);
void			check_map_parser(t_parser *p);

// CONTROLS ============================================================

void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			rotate(t_player *player, float angle);

// DATA_TO_GAME ========================================================

void			copy_map(t_parser *p, t_game *g);
void			set_player_dir(t_game *g, char dir);
void			set_player_plane(t_game *g, char dir);
void			data_to_game(t_parser *p, t_game *g);

// DRAW ========================================================

void			draw_sky_and_floor(t_game *game, int x);
int				dim_color(t_color *color, double dist);
void			draw_empty_stripe(t_game *game, int x, int start, int end);
void			textured_stripe(t_game *game, int x, int start, int end);
void			draw_stripe(t_game *game, int x, int start, int end);

// DUP_MAP ========================================================

char			**dup_map(t_parser *p);

// FREE_UTILS ========================================================

void			error_exit(char *msg);
void			free_split(char **arr);

// HOOKS ==========================================================

void			key_hook(mlx_key_data_t keydata, void *params);
void			main_hook(void *params);

// INITIALIZE ======================================================

void			set_plane(t_player *player, char dir);
void			set_dir(t_player *player, char dir);
void			parser_init(t_parser *p);

// LOAD_MAP_PARSER ======================================================

int				max_width(char **m);
char			*pad(char *row, int w);
int				count_map_lines(char **m);
void			load_map_parser(t_parser *p, char **lines);

// PARSE_COLOR ======================================================

void			parse_color(t_color *c, char *s);

// PARSE_FILE ========================================================

int				is_map_line(char *line);
int				find_map_start(char **lines);
void			validate_map_block(char **lines, int start);
void			check_all_textures(t_parser *p);
void			parse_file(t_parser *p, char *path);

// PARSE_TEXTURE ========================================================

void			parse_texture(t_parser *p, char *id, char **dst, char *line);
void			parse_color_line(t_color *c, char *line, char *err);
void			parse_ident_line(t_parser *p, char *l);
mlx_texture_t	*load_png_strict(char *path);
void			load_textures_from_parser(t_game *game, t_parser *p);

// RAYCAST ========================================================

void			ray_refresh(t_ray *ray, t_player *player, int x);
void			ray_dir(t_ray *ray, t_player *player);
void			check_hit(t_game *game);
void			set_dist(t_game *game);
void			raycast(t_game *game);

// READ_FILE_TO_ARRY =========================================================

int				count_lines(char *str);
char			*get_line_from_str(char *str, int *pos);
char			**split_preserving_empty(char *str);
char			**read_file_to_array(char *path);

// TEXTURE ========================================================

t_color			px_tx(mlx_texture_t *texture, int x, int y);
void			get_wall_texture(t_game *game);
void			set_tex_params(t_wall_tex *wall_tex, t_ray *ray);
void			get_wall_height(t_game *game, int x);

// UTILS ========================================================

int				open_and_init(char *path, char **accum);
int				get_rgba(int r, int g, int b, int a);
int				is_map_char(char c);
int				is_ident(char *l);
int				is_empty_line(char *ln);

#endif
