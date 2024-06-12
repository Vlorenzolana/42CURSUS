/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:32:23 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/06/12 18:40:30 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(int count, void *ptr)
{
	if (ptr == NULL)
		count = putstr("(nil)", count);
	else
	{
		count = putstr("0x", count);
		count = puthexnbr((size_t)ptr, count, 'p');
	}
	return (count);
}

int	find_specifer(const char *str, int i, int count, va_list list)
{
	void	*ptr;

	if (str[i + 1] == 'c')
		count = print_char(va_arg(list, int), count);
	if (str[i + 1] == '%')
		count = print_char('%', count);
	if (str[i + 1] == 's')
	{
		count = putstr(va_arg(list, const char *), count);
	}
	if ((str[i + 1] == 'i') || (str[i + 1] == 'd'))
		count = putnbr(va_arg(list, int), count);
	if (str[i + 1] == 'u')
		count = putnbr_pos(va_arg(list, unsigned int), count);
	if (str[i + 1] == 'x' || str[i + 1] == 'X')
		count = puthexnbr(va_arg(list, unsigned int), count, str[i + 1]);
	if (str[i + 1] == 'p')
	{
		ptr = va_arg(list, void *);
		count = print_ptr(count, ptr);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str && str[i] != '\0')
	{
		if (str[i] != '%')
		{
			count = print_char(str[i], count);
		}
		else
		{
			count = find_specifer(str, i, count, list);
			i++;
		}
		i++;
	}
	va_end(list);
	return (count);
}
