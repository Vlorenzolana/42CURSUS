/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:38:45 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/16 12:52:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_it_negative(long m);
int	sizer(long m);

char	*ft_itoa(int n)
{
	long	m;
	int		size;
	char	*str;

	m = n;
	size = sizer(m);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (m == 0)
		str[0] = '0';
	if (m < 0)
	{
		m *= -1;
		str[0] = '-';
	}
	str[size--] = '\0';
	while (m > 0)
	{
		str[size--] = m % 10 + '0';
		m = m / 10;
	}
	return (str);
}

int	sizer(long m)
{
	int	size;

	size = 0;
	if (m == 0)
		size = 1;
	if (m < 0)
	{
		m *= -1;
		size++;
	}
	while (m > 0)
	{
		m /= 10;
		size++;
	}
	return (size);
}

#include <stdio.h> // For printf and free
int	main(void)
{
    int num_to_convert = -12345;
	char	*str = ft_itoa(num_to_convert);

	while (*str)
	{
		write(1, str, 1);
		str++;
	}

    printf("Integer %d converted to string: %s\n", num_to_convert, str);

   // free(str); // Important: Free the memory allocated by ft_itoa

    return (0);
}