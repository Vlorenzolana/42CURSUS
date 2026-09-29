/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:32:24 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/18 11:32:25 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

void	ScalarConverter::convert(const std::string &str)
{
	if (isSpecial(str))
	{
		printSpecial(str);
		return ;
	}

	if (isChar(str))
	{
		char	c;
		if (str.length() == 1)
			c = str[0];
		else
			c = str[1];
		printFromDouble(static_cast<double>(c));
		return ;
	}

	if (isInt(str))
	{
		char	*end;
		errno = 0;
		long	l;
		l = std::strtol(str.c_str(), &end, 10);
		if (*end != '\0')
		{
			std::cout << "Invalid input" << std::endl;
			return ;
		}
		printFromDouble(static_cast<double>(l));
		return ;
	}

	if (isFloat(str))
	{
		std::string	tmp = str.substr(0, str.length() - 1);
		char	*end;
		errno = 0;
		double	d = std::strtod(tmp.c_str(), &end);
		if (*end != '\0')
		{
			std::cout << "Invalid input" << std::endl;
			return ;
		}
		printFromDouble(d);
		return ;
	}

	if (isDouble(str))
	{
		char	*end;
		errno = 0;
		double	d = std::strtod(str.c_str(), &end);
		if (*end != '\0')
		{
			std::cout << "Invalid input" << std::endl;
			return ;
		}
		printFromDouble(d);
		return ;
	}

	std::cout << "Invalid input" << std::endl;
}
