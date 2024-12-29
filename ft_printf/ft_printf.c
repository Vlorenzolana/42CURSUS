/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:32:23 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/29 11:31:23 by vlorenzo         ###   ########.fr       */
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

	if (str[i] == 'c')
		count = print_char(va_arg(list, int), count);
	if (str[i] == '%')
		count = print_char('%', count);
	if (str[i] == 's')
	{
		count = putstr(va_arg(list, const char *), count);
	}
	if ((str[i] == 'i') || (str[i] == 'd'))
		count = putnbr(va_arg(list, int), count);
	if (str[i] == 'u')
		count = putnbr_pos(va_arg(list, unsigned int), count);
	if (str[i] == 'x' || str[i] == 'X')
		count = puthexnbr(va_arg(list, unsigned int), count, str[i]);
	if (str[i] == 'p')
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
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count = find_specifer(str, i, count, list);
		}
		else
		{
			count = print_char(str[i], count);
		}
		i++;
	}
	va_end(list);
	return (count);
}

int	main(void)
{
	int	count;
	char *str;
	str = NULL;
	int n = -42;
	unsigned int un = -42;
	char c = 'a';

	printf("***1*** FT_PRINTF\n");
	count = ft_printf(" %s %c %% ", str, '1');
	printf("\ncount = %d\n", count);
	printf("***1*** PRINTF\n");
	count = printf(" %s %c %% ", str, '1');
	printf("\ncount = %d\n", count);
	printf("\n");

	printf("***2*** FT_PRINTF\n");
	count = ft_printf(" %u %d %c ", un, n, c);
	printf("\ncount = %d\n", count);
	printf("***2*** PRINTF\n");
	count = printf(" %u %d %c ", un, n, c);
	printf("\ncount = %d\n", count);
	printf("\n");
	
	return (0);
}