/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:56:33 by otboumeh          #+#    #+#             */
/*   Updated: 2024/05/04 16:57:41 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*DESCRIPTION:
The approach of the function design in puthexnbr is very similar to putnbr.
Uses recursion for calling the function itself but sending argument / 16 as
parameter, instead of / 10, as in putnbr.
Once the parameter sent to puthexnbr is smaller than 16, it prints the 
respective character of the string chosen.
---------------------------------------------------------------------------*/

int	puthexnbr(size_t arg, int count, char x_type)
{
	if (arg >= 16)
	{
		count = puthexnbr(arg / 16, count, x_type);
	}
	if ((x_type == 'x') || (x_type == 'p'))
		count = print_char("0123456789abcdef"[arg % 16], count);
	if (x_type == 'X')
		count = print_char("0123456789ABCDEF"[arg % 16], count);
	return (count);
}
