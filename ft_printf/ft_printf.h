/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:11:18 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/06/16 17:50:59 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h> //For variadic function: va_list, va_start, va_arg, va_end
# include <unistd.h>
# include <limits.h> //Includes INT_MIN and INT_MAX values
# include <stdlib.h>

//ft_printf.c

int	ft_printf(const char *str, ...);
int	find_specifer(const char *str, int i, int count, va_list list);
int	print_ptr(int count, void *ptr);

//print_fn.c

int	print_char(char c, int count);
int	putstr(const char *str, int count);
int	putnbr(int n, int count);
int	putnbr_pos(unsigned int n, int count);
int	puthexnbr(size_t n, int count, char x_type);

#endif