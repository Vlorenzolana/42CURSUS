/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:36 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/17 17:49:47 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_game	*g_game = NULL;

int	main(int argc, char **argv)
{
	t_game		game;
	t_parser	parser;

	g_game = &game;
	gc_init(&game.gc);
	if (!check_args(argc, argv))
		return (1);
	parser_init(&parser);
	parse_file(&parser, argv[1]);
	data_to_game(&parser, &game);
	load_textures_from_parser(&game, &parser);
	game.mlx = mlx_init(WIN_W, WIN_H, "cub3D", false);
	mlx_set_cursor_mode(game.mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(game.mlx, WIN_W, WIN_H);
	if (!game.mlx)
		error_exit("MLX init failed");
	game.img = mlx_new_image(game.mlx, WIN_W, WIN_H);
	mlx_image_to_window(game.mlx, game.img, 0, 0);
	mlx_cursor_hook(game.mlx, main_mouse_hook, &game);
	mlx_loop_hook(game.mlx, main_hook, &game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	game_clear(&game);
	return (0);
}
