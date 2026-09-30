/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:28:55 by dalabrad          #+#    #+#             */
/*   Updated: 2025/03/06 12:16:20 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_puthex(unsigned int n, const char format)
{
	int		len;

	if (format != 'x' && format != 'X')
		return (-1);
	len = 0;
	if (n < 10)
	{
		len += ft_putchar('0' + n);
	}
	else if (9 < n && n < 16)
	{
		if (format == 'x')
			len += ft_putchar('a' + n - 10);
		else
			len += ft_putchar('A' + n - 10);
	}
	else
	{
		len += ft_puthex(n / 16, format);
		len += ft_puthex(n % 16, format);
	}
	return (len);
}
