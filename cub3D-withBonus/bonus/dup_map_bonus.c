/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:16:20 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/16 17:16:22 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

char	**dup_map(t_parser *p)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (p->map_h + 1));
	if (!copy)
		error_exit("dup_map malloc");
	i = -1;
	while (++i < p->map_h)
		copy[i] = ft_strdup(p->map[i]);
	copy[i] = NULL;
	gc_add(&g_game->gc, copy, (void (*)(void *))free_split);
	return (copy);
}
