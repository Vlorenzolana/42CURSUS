/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:48:53 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/16 09:07:10 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    char	digit;
    
    if (n == -2147483648)
        write(fd, "-2147483648", 11);

    else if (n < 0)
    {
        write(fd, "-", 1);
        n = -n;
        ft_putnbr_fd(n, fd);
    }
    else
    {
        if (n > 9)
        {
            ft_putnbr_fd(n / 10, fd);
            ft_putnbr_fd(n % 10, fd);
        }
        else
        {
            digit = n + 48;
            write(fd, &digit, 1);
        }
    }
}

/* #include "libft.h"
#include <unistd.h> // For STDOUT_FILENO

int	main(void)
{
	int		n = -5;
	int		fd = 1;

	ft_putnbr_fd(n, fd);
	return (0);
} */