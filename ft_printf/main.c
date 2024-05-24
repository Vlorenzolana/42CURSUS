/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:03:45 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/24 13:03:23 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main() {
    char *ptr;

    ptr = 0;
    
	ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "");
	ft_printf("Integer: %d\n", -12345);
	ft_printf("Unsigned: %u\n", 12345);
	ft_printf("Hex (lower): %x\n", 3735);
	ft_printf("Hex (upper): %X\n", 3735);
	ft_printf("Pointer: %p\n", ptr);
	ft_printf("Percent sign: %%\n");

	return 0;
}