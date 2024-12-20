/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:48 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/17 16:31:39 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

t_msg			g_msg;

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

void	bit_handler(int signal)
{
	unsigned char	a;

	if (signal == SIGUSR2)
		g_msg.c |= (1 << g_msg.i);
	else if (signal == SIGUSR1)
		g_msg.c &= ~(1 << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 8)
	{
		a = reverse_bits(g_msg.c);
		ft_printf("%c", a);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int	main(void)
{
	ft_printf("My Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_handler);
		signal(SIGUSR1, bit_handler);
		pause();
	}
	write(1, "\0", 1);
	return (0);
}
