/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:15:57 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/16 17:15:59 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	move_forward(t_game *game)
{
	double	newposx;
	double	newposy;
	double	collision_margin;

	collision_margin = 0.2;
	newposx = game->player.pos_x + game->player.dir_x * game->player.speed;
	newposy = game->player.pos_y + game->player.dir_y * game->player.speed;
	if (game->map.map_array[(int)game->player.pos_y][(int)(newposx
		+ game->player.dir_x * collision_margin)] != '1')
		game->player.pos_x = newposx;
	if (game->map.map_array[(int)(newposy + game->player.dir_y
			* collision_margin)][(int)game->player.pos_x] != '1')
		game->player.pos_y = newposy;
}

void	move_backward(t_game *game)
{
	double	newposx;
	double	newposy;
	double	collision_margin;

	collision_margin = 0.2;
	newposx = game->player.pos_x - game->player.dir_x * game->player.speed;
	newposy = game->player.pos_y - game->player.dir_y * game->player.speed;
	if (game->map.map_array[(int)game->player.pos_y][(int)(newposx
		- game->player.dir_x * collision_margin)] != '1')
		game->player.pos_x = newposx;
	if (game->map.map_array[(int)(newposy - game->player.dir_y
			* collision_margin)][(int)game->player.pos_x] != '1')
		game->player.pos_y = newposy;
}

void	move_right(t_game *game)
{
	double	newposx;
	double	newposy;
	double	collision_margin;

	collision_margin = 0.2;
	newposx = game->player.pos_x - game->player.dir_y * game->player.speed;
	newposy = game->player.pos_y + game->player.dir_x * game->player.speed;
	if (game->map.map_array[(int)game->player.pos_y][(int)(newposx
		- game->player.dir_y * collision_margin)] != '1')
		game->player.pos_x = newposx;
	if (game->map.map_array[(int)(newposy + game->player.dir_x
			* collision_margin)][(int)game->player.pos_x] != '1')
		game->player.pos_y = newposy;
}

void	move_left(t_game *game)
{
	double	newposx;
	double	newposy;
	double	collision_margin;

	collision_margin = 0.2;
	newposx = game->player.pos_x + game->player.dir_y * game->player.speed;
	newposy = game->player.pos_y - game->player.dir_x * game->player.speed;
	if (game->map.map_array[(int)game->player.pos_y][(int)(newposx
		+ game->player.dir_y * collision_margin)] != '1')
		game->player.pos_x = newposx;
	if (game->map.map_array[(int)(newposy - game->player.dir_x
			* collision_margin)][(int)game->player.pos_x] != '1')
		game->player.pos_y = newposy;
}

void	rotate(t_player *player, float angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	player->plane_x = player->plane_x * cos(angle) - player->plane_y
		* sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}
