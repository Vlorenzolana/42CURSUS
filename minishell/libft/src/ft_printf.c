/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:55:24 by dalabrad          #+#    #+#             */
/*   Updated: 2025/03/06 12:16:20 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_format(va_list args, const char fmt)
{
	void	*ptr;

	if (fmt == 'c')
		return (ft_putchar((char)(va_arg(args, int))));
	else if (fmt == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (fmt == 'x' || fmt == 'X')
		return (ft_puthex(va_arg(args, unsigned int), fmt));
	else if (fmt == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (fmt == '%')
		return (ft_putchar('%'));
	else if (fmt == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_putaddress(ptr));
		return (ft_putstr("0x0"));
	}
	else
		return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && ft_strchr("cspdiuxX%", *(fmt + 1)) && *(fmt + 1))
		{
			len += ft_format(args, *(fmt + 1));
			fmt++;
		}
		else if (*fmt != '%')
			len += ft_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	return (len);
}
