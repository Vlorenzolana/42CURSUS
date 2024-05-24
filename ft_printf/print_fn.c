/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:09:50 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/24 13:50:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, int count)
{
	write(1, &c, 1);
	return (count + 1);
}

int	putstr(const char *str, int count)
{
	if (!str)
	{
		count = putstr("(nil)", count);
	}
	while (*str)
	{
		count = print_char(*str, count);
		str++;
	}
	return (count);
}

int	putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		count = putstr("-2147483648", count);
	}
	else
	{
		if (n < 0)
		{
			count = print_char('-', count);
			n = -n;
		}
		if (n >= 10)
		{
			count = putnbr(n / 10, count);
		}
		count = print_char(n % 10 + '0', count);
	}
	return (count);
}

int	putnbr_pos(unsigned int n, int count)
{
	if (n >= 10)
	{
		count = putnbr_pos(n / 10, count);
	}
	count = print_char(n % 10 + '0', count);
	return (count);
}

int	puthexnbr(size_t arg, int count, char x_type)
{
	if (arg >= 16)
	{
		count = puthexnbr(arg / 16, count, x_type);
	}
	if (x_type == 'x')
		count = print_char("0123456789abcdef"[arg % 16], count);
	if (x_type == 'X')
		count = print_char("0123456789ABCDEF"[arg % 16], count);
	return (count);
}
