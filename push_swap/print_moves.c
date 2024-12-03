																																					/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:24:26 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/11/07 19:25:44 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(char moves[], int j)
{
	if (moves[j] == '1')
		write(1, "sa\n", 3);
	else if (moves[j] == '2')
		write(1, "sb\n", 3);
	else if (moves[j] == '4')
		write(1, "pa\n", 3);
	else if (moves[j] == '5')
		write(1, "pb\n", 3);
	else if (moves[j] == '6')
		write(1, "ra\n", 3);
	else if (moves[j] == '7')
		write(1, "rb\n", 3);
	else if (moves[j] == '9')
		write(1, "rra\n", 4);
	else if (moves[j] == '3')
		write(1, "rrb\n", 4);
}
