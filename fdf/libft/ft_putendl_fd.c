/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:50:20 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 08:41:50 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/* 
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        write(2, "Usage: ./program_name <string>\n", 31);
        return 1;
    }

    // Example usage: write to standard output (fd = 1)
    ft_putendl_fd(argv[1], 1);

    // Example usage: write to standard error (fd = 2)
    ft_putendl_fd("This is an error message", 2);

    return 0;
}

// Function definition for ft_putendl_fd
void ft_putendl_fd(char *str, int fd)
{
    int i = 0;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
    write(fd, "\n", 1);
} */