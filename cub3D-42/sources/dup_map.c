/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:36:57 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/14 18:25:42 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**dup_map(t_parser *p)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (p->map_h + 1));
	i = -1;
	if (!copy)
		error_exit("dup_map malloc");
	while (++i < p->map_h)
		copy[i] = ft_strdup(p->map[i]);
	copy[i] = NULL;
	return (copy);
}
