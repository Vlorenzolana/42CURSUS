/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:22:36 by jcluzet           #+#    #+#             */
/*   Updated: 2025/05/22 19:03:09 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
char	*ft_itoa(int nbr);

int main(int argc, char **argv)
{
   (void)argc;
    printf("%s\n", ft_itoa(atoi(argv[1])));
    return (0);
}
