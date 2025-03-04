/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:36:06 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/03/04 15:15:57 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	digit_only(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	digit_str_atoi(char *str)
{
	unsigned long long int	nb;
	int						i;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

bool	valid_args(int ac, char **av)
{
	int	i;
	int	nb;

	nb = 0;
	i = 1;
	while (i < ac)
	{
		if (!digit_only(av[i]))
			return (msg("%s invalid input: enter unsigned int range 0-2147483647\n",
					av[i], false));
		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
			return (msg("%s no-valid: range between 1 and %s philosophers\n",
					STR_MAX_PHILOS, false));
		if (i != 1 && nb == -1)
			return (msg("%s invalid input: enter unsigned int range 0-2147483647\n",
					av[i], false));
		i++;
	}
	return (true);
}

/*
 *	digit_only:
 *	Checks if a string contains only digits 0 - 9.
 *	Returns true if the string only contains digits.
 *	Returns false if the string contains a character that is not a digit.
 *
 *	digit_str_atoi:
 *	Converts a digit-only string into a unsigned integer.
 *	Returns the converted num between 0 - INT MAX.
 *	Returns -1 if num exceeds INT MAX.
 *
 *	valid_args:
 *	Checks if all required arguments are valid, i.e. is a string of
 *	digits only, which does not exceed INT MAX. Also checks if the number
 *	of philosophers is valid (between 1 and MAX_PHILOS).
 *	Returns true if all arguments are valid, false if one of them is
 *	invalid.
 */