/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 07:07:55 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/20 16:54:50 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	print_char(double value)
{
	std::cout << "char:	";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void	print_int(double value)
{
	std::cout << "int:	";
	if (std::isnan(value) || std::isinf(value)
		|| value > static_cast<double>(std::numeric_limits<int>::max())
		|| value < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void	print_float(double value)
{
	std::cout << "float:	";
	float f = static_cast<float>(value);
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
	else if (f == static_cast<long long>(f))
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

static void	print_double(double value)
{
	std::cout << "double:	";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
	else if (value == static_cast<long long>(value))
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << value << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	double value;

	if (literal.length() == 1 && !isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else
		value = atof(literal.c_str());

	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}