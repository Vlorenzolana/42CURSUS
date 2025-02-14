/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:17:56 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/01/31 17:14:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_grid(t_point **grid, int i)
{
	while (i > 0)
	{
		i--;
		free(grid[i]);
		grid[i] = NULL;
	}
	free(grid[i]);
	grid[i] = NULL;
	free(grid);
}

void	free_array(char **array)
{
	char	**aux;

	aux = array;
	while (*aux)
	{
		free(*aux);
		*aux = NULL;
		aux++;
	}
	free(*aux);
	free(array);
}

void	print_error(const char *error_message)
{
	write(1, error_message, ft_strlen(error_message));
	exit(-1);
}
