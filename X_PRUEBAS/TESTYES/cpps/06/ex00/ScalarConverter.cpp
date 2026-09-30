/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:00:25 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/20 18:20:31 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){(void)other;}
ScalarConverter::~ScalarConverter(){}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& other){(void)other; return *this;}

template <typename T>
static void	printChar(T n)
{
	if (std::isnan(n) || n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(n)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(n) << "'" << std::endl;
}

template <typename T>
static void	printInt(T n)
{
	if (std::isnan(n) || n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
}

template <typename T>
static void	printFloat(T n)
{
	float f = static_cast<float>(n);
	
	if (std::isinf(f) || std::isnan(f))
		std::cout << "float: " << f << "f" << std::endl;
	else if (n < -std::numeric_limits<float>::max() || n > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
}

template <typename T>
static void	printDouble(T n)
{
	double d = static_cast<double>(n);

	if (std::isinf(d) || std::isnan(d))
		std::cout << "double: " << d << std::endl;
	else if (n < -std::numeric_limits<double>::max() || n > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

template <typename T>
static void	Convert(T n)
{
	printChar(n);
	printInt(n);
	printFloat(n);
	printDouble(n);
}

void	ScalarConverter::convert(std::string input)
{
	char *endptr;
	
	errno = 0;
	int i = std::strtol(input.c_str(), &endptr, 10);
	if (errno == 0 && endptr[0] == '\0')
		return (Convert(i));

	char c = input[0];
	if (input.size() == 1)
		return (Convert(c));

	errno = 0;
	float f = std::strtof(input.c_str(), &endptr);
	if (errno == 0 && endptr[0] == 'f' && endptr[1] == '\0')
		return (Convert(f));

	errno = 0;
	double d = std::strtod(input.c_str(), &endptr);
	if (errno == 0 && endptr[0] == '\0')
		return (Convert(d));

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
