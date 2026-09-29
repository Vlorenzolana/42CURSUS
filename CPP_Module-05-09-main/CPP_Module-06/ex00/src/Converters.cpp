/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:32:11 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/18 11:32:13 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void	printSpecial(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str[0] == '-')
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void	printFromDouble(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int: ";
	if (std::isnan(value) || value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: ";
	if (value < -std::numeric_limits<float>::max() ||
		value > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(value) << "f" << std::endl;

	std::cout << "double: " << value << std::endl;
}
