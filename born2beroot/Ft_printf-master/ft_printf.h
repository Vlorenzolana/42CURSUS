/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:57:16 by otboumeh          #+#    #+#             */
/*   Updated: 2024/05/04 16:58:49 by otboumeh         ###   ########.fr       */
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

//printing.c

int	print_char(char c, int count);
int	putstr(char *str, int count);
int	putnbr(int n, int count);
int	putnbr_pos(unsigned int n, int count);

//put_hex.c

int	puthexnbr(size_t n, int count, char x_type);


#endif