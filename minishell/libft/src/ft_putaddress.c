/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:27:31 by dalabrad          #+#    #+#             */
/*   Updated: 2025/03/06 12:16:20 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_puthexlong(unsigned long n)
{
	int		len;

	len = 0;
	if (n < 10)
		len += ft_putchar('0' + n);
	else if (9 < n && n < 16)
		len += ft_putchar('a' + n - 10);
	else
	{
		len += ft_puthexlong(n / 16);
		len += ft_puthexlong(n % 16);
	}
	return (len);
}

int	ft_putaddress(void *ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthexlong((unsigned long)ptr);
	return (len);
}
