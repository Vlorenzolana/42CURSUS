/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:22:19 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/30 20:03:58 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_point	**grid;
	t_map	map;

	(void)argv;
	if (argc != 2)
		print_error("Error: Arguments must be exactly 2.\n");
	grid = load_map(argv[1], &map);
	algo_fdf(grid, &map);
	return (0);
}
