/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:40:03 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 08:42:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
/* 
#include "fcntl.h"
int main(void)
{
    char *str = "Hello, world!";
    int fd;

    // Print to standard output (file descriptor 1)
    ft_putstr_fd(str, 1);

    // Open a file for writing (create if it does not exist, truncate if it does)
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Print to the file
    ft_putstr_fd(str, fd);

    // Close the file
    if (close(fd) == -1)
    {
        perror("Error closing file");
        return 1;
    }

    return 0;
} */