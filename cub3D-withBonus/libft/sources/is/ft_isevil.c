/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isevil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:00:25 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isevil(char *av)
{
	if (av[0] == '<' && (av[1] != '\0' || av[1] != ' '))
	{
		printf("Input: check redirections\n");
		return (-1);
	}
	if (av[0] == '|' && (av[1] != '\0' || av[1] != ' '))
	{
		printf("Input: check redirections\n");
		return (-1);
	}
	if (av[0] == '>' && (av[1] == '>' && (av[2] != '\0' || av[3] != ' ')))
	{
		printf("Input: check redirections\n");
		return (-1);
	}
	return (0);
}
