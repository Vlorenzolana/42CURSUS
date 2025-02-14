/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:48:57 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/02/07 15:22:36 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	digit = (nbr % 10) + '0';
	ft_putchar(digit);
}

int	main(int ac, char **av)
{
	int i;
	int number;

	i = 1;
	if (ac == 2)
	{
		number = ft_atoi(av[1]);
		while (i < 10)
		{
			ft_putnbr(i);
			write(1, " * ", 3);
			ft_putnbr(number);
			write(1, " = ", 3);
			ft_putnbr(i * number);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
