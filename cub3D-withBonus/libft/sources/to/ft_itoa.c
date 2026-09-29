/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:56:02 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/09/18 19:20:45 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static	char	*contador(long i, size_t len)
{
	char	*nb;

	nb = (char *)ft_calloc((len + 1), sizeof(char));
	if (nb == NULL)
	{
		return (NULL);
	}
	if (i < 0)
	{
		i *= -1;
		nb[0] = '-';
	}
	while (i > 0)
	{
		nb[len - 1] = i % 10 + 48;
		len--;
		i /= 10;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	int	x;
	int	y;

	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	x = 0;
	y = n;
	while (y != 0)
	{
		y /= 10;
		x++;
	}
	return (contador(n, x + (n < 0)));
}
