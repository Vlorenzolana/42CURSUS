/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:52:18 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/17 16:31:18 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

static void	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

static void	send_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		shift = 8;
		while (shift--)
		{
			if (str[i] >> shift & 1)
			{
				if ((kill(pid, SIGUSR2)) == -1)
					ft_exit("Error: Failed to send SIGUSR2.\n");
			}
			else
			{
				if ((kill(pid, SIGUSR1)) == -1)
					ft_exit("Error: Failed to send SIGUSR1.\n");
			}
			usleep(200);
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			ft_exit("Error: Invalid PID.\n");
		str = argv[2];
		send_bit(pid, str, ft_strlen(str) + 1);
	}
	else
		ft_printf("Usage: %s <PID> <MESSAGE>\n", argv[0]);
	return (0);
}
