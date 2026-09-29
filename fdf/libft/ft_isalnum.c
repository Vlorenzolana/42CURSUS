/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:58:22 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/14 16:14:46 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')
		|| (i >= '0' && i <= '9'))
		return (1);
	return (0);
}

/* #include "stdio.h"
int main(void)
{
	printf( "Prueba a %d \n", ft_isalnum('a'));
	printf( "Prueba 0 %d \n", ft_isalnum('0'));
	printf( "Prueba 4 %d \n", ft_isalnum('4'));
	printf( "Prueba P %d \n", ft_isalnum('P'));

	return(0);
} */

/*
The isalnum() function tests for isalpha() + isdigit()
is true. The value of the argument must be representable
as an unsigned char or the value of EOF. In the ASCII
character set,
this includes the following characters:
*/

/*
60 ``0''     061 ``1''     062 ``2''     063 ``3''     064 ``4''
065 ``5''     066 ``6''     067 ``7''     070 ``8''     071 ``9''
101 ``A''     102 ``B''     103 ``C''     104 ``D''     105 ``E''
106 ``F''     107 ``G''     110 ``H''     111 ``I''     112 ``J''
113 ``K''     114 ``L''     115 ``M''     116 ``N''     117 ``O''
120 ``P''     121 ``Q''     122 ``R''     123 ``S''     124 ``T''
125 ``U''     126 ``V''     127 ``W''     130 ``X''     131 ``Y''
132 ``Z''     141 ``a''     142 ``b''     143 ``c''     144 ``d''
145 ``e''     146 ``f''     147 ``g''     150 ``h''     151 ``i''
152 ``j''     153 ``k''     154 ``l''     155 ``m''     156 ``n''
157 ``o''     160 ``p''     161 ``q''     162 ``r''     163 ``s''
164 ``t''     165 ``u''     166 ``v''     167 ``w''     170 ``x''
171 ``y''     172 ``z''
*/