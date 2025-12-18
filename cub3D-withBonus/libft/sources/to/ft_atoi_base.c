/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:41:43 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	ft_strchr_i(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (ft_strchr_i(base, *str) != -1
		|| ft_strchr_i(base, ft_toupper(*str)) != -1)
	{
		if (ft_strchr_i(base, *str) != -1)
			nb = nb * ft_strlen(base) + ft_strchr_i(base, *str++);
		else
			nb = nb * ft_strlen(base) + ft_strchr_i(base, ft_toupper(*str++));
	}
	return (nb * sign);
}
