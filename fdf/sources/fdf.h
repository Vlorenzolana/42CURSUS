/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:57:06 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/31 18:15:32 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define ISO_ANGLE 0.523599

# include "../MLX/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_bresenham
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				step_x;
	int				step_y;
	int				error;
}					t_bresenham;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	double			iso_x;
	double			iso_y;
	double			iso_scaled_x;
	double			iso_scaled_y;
	struct s_map	*map;
}					t_point;

typedef struct s_map
{
	int				rows;
	int				cols;
	int				scale;
	int				initial_scale;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			offset_x;
	double			offset_y;
	double			angle;
	int				point_cloud;
	t_point			**grid;
	mlx_image_t		*img;
	mlx_t			*mlx;
}					t_map;

int					main(int argc, char **argv);

t_point				**load_map(char *argv1, t_map *map);
t_point				**alloc_grid(t_map *map);
void				fill_grid(t_point **grid, char *route_to_map, t_map *map);

void				prepare_grid(t_point **grid, t_map *map);
void				ft_scale_iso(t_point *point, t_map *map);
void				ft_iso_coords(t_point *point);

void				render_grid(mlx_image_t *img, t_point **grid, t_map *map);
void				scale_and_offset(t_point **grid, t_map *map, int w_width,
						int w_height);
int					grid_overflow(t_point *point);

void				render_lines(mlx_image_t *img, t_point **grid, t_map *map);
void				draw(mlx_image_t *img, t_point origin, t_point target,
						uint32_t color);

void				algo_fdf(t_point **grid, t_map *map);
void				mlx_key_handle(mlx_t *mlx, mlx_keyfunc func, void *param);

void				algo_bresenham(t_bresenham *b, t_point origin,
						t_point target);
void				step_dir(int *step, int a, int b);
void				get_coordinate(int *x, int *y, t_point point);
void				draw_step(t_bresenham *b);

void				hook_handle(mlx_key_data_t keydata, void *param);

void				print_error(const char *error_message);
void				free_array(char **array);
void				free_grid(t_point **grid, int i);

#endif