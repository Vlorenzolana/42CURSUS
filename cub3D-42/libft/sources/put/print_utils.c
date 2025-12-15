/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:29:16 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	print_char(char c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}

int	print_str(char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (len + 6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	print_number(int nb, int len)
{
	if (nb == -2147483648)
	{
		return (print_str("-2147483648", len));
	}
	else if (nb < 0)
	{
		len = print_char('-', len);
		nb = -nb;
	}
	if (nb >= 10)
	{
		len = print_number(nb / 10, len);
	}
	len = print_char (nb % 10 + '0', len);
	return (len);
}

int	print_positive_number(unsigned int nb, int len)
{
	if (nb >= 10)
	{
		len = print_positive_number(nb / 10, len);
	}
	len = print_char (nb % 10 + '0', len);
	return (len);
}

int	print_hex(size_t nb, int len, char format)
{
	if (nb >= 16)
	{
		len = print_hex(nb / 16, len, format);
	}
	if ((format == 'x') || (format == 'p'))
	{
		len = print_char("0123456789abcdef"[nb % 16], len);
	}
	if (format == 'X')
	{
		len = print_char("0123456789ABCDEF"[nb % 16], len);
	}
	return (len);
}
