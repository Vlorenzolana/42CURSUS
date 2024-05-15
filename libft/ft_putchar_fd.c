/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:35:05 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/15 13:40:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putchar_fd(char c, int fd)
{
    /* first parameter is the file descriptor
     * second parameter is the address to the character
     */
    write(fd, &c, 1);
}
/* 
#include <unistd.h>
int main(void) {
    char character = 'H';
    int fd = STDOUT_FILENO; // Standard output file descriptor

    // Print the character 'H' to standard output
    ft_putchar_fd(character, fd);

    // Alternatively, print a string character by character
    char *message = "Hello, world!";
    int i = 0;
    while (message[i]) {
        ft_putchar_fd(message[i], fd);
        i++;
    }

    return 0;
} */