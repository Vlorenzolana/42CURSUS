/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:16:44 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/17 17:50:12 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	key_hook(mlx_key_data_t keydata, void *params)
{
	t_game	*game;

	game = params;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

void	main_mouse_hook(double pos_x, double pos_y, void *params)
{
	t_game	*game;
	double	angle;

	game = params;
	(void)pos_y;
	if (pos_x != WIN_W / 2)
	{
		angle = (0.002 * (pos_x - WIN_W / 2) * game->player.rotate_speed);
		rotate(&game->player, angle);
	}
	if (pos_x > (WIN_W / 2) + 50)
		mlx_set_mouse_pos(game->mlx, (WIN_W / 2) + 50, WIN_H / 2);
	if (pos_x < (WIN_W / 2) - 50)
		mlx_set_mouse_pos(game->mlx, (WIN_W / 2) - 50, WIN_H / 2);
}

void	main_hook(void *params)
{
	t_game	*game;

	game = (t_game *)params;
	raycast(game);
	if (game -> bonus)
	{
		draw_minimap(game);
		draw_minimap_player(game);
		draw_minimap_dir(game);
	}
	if (mlx_is_key_down(game -> mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game -> mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game -> mlx, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game -> mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game -> mlx, MLX_KEY_LEFT))
		rotate(&game -> player, -game -> player.rotate_speed);
	if (mlx_is_key_down(game -> mlx, MLX_KEY_RIGHT))
		rotate(&game -> player, game->player.rotate_speed);
}
