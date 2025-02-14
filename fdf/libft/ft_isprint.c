/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vlorenzo <vlorenzo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:04:46 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/04/11 12:52:41 by Vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}

/*
#include "stdio.h"

int main(void)
{
	int c;

	c = 'a'; //te sale warning pero entra igual
	ft_isprint(c);
	return(0);
} */