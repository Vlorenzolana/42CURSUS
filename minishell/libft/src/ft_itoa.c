/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:45:37 by dalabrad          #+#    #+#             */
/*   Updated: 2025/03/06 12:16:20 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	nbr_size(int n)
{
	unsigned int	nbr;
	size_t			size;

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	size = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			size;
	char			*rtrn;

	size = nbr_size(n);
	if (n > 0)
		nbr = n;
	else
	{
		nbr = -n;
		size++;
	}
	rtrn = (char *)malloc(sizeof(char) * (size + 1));
	if (rtrn == NULL)
		return (NULL);
	rtrn[size] = '\0';
	while (size > 0)
	{
		rtrn[size - 1] = '0' + (nbr % 10);
		nbr = nbr / 10;
		size--;
	}
	if (n < 0)
		rtrn[0] = '-';
	return (rtrn);
}
