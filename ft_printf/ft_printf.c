/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:32:23 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/23 18:06:53 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_specifer(const char *str, int i, int count, va_list list)
{
	if (!str)
		count = putstr("(null)", count);
	if (str[i + 1] == 'c')
		count = print_char(va_arg(list, int), count);
	if (str[i + 1] == '%')
		count = print_char('%', count);
	if (str[i + 1] == 's')
		count = putstr(va_arg(list, const char *), count);
	if ((str[i + 1] == 'i') || (str[i + 1] == 'd'))
		count = putnbr(va_arg(list, int), count);
	if (str[i + 1] == 'u')
		count = putnbr_pos(va_arg(list, unsigned int), count);
	if (str[i + 1] == 'x')
		count = puthexnbr(va_arg(list, unsigned int), count, 'x');
	if (str[i + 1] == 'X')
		count = puthexnbr(va_arg(list, unsigned int), count, 'X');
	if (str[i + 1] == 'p')
	{
		count = putstr("0x", count);
		count = puthexnbr(va_arg(list, size_t), count, 'p');
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
	while (str[i] != '\0')
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
/* int main() {
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "1Hello, world!");
	ft_printf("Integer: %d\n", -12345);
	ft_printf("Unsigned: %u\n", 12345);
	ft_printf("Hex (lower): %x\n", 3735);
	ft_printf("Hex (upper): %X\n", 3735);
	ft_printf("Pointer: %p\n", &main);
	ft_printf("Percent sign: %%\n");

	return 0;
} */