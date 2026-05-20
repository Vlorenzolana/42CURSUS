/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 07:07:55 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/04/08 19:05:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string &literal)
{
	if (literal.length() == 1  && !isdigit(literal[0]))
	{
		char single_char = literal[0];
		std::cout << "char:	'" << single_char << "'" << std::endl;
		std::cout << "int:	" << static_cast<int>(single_char) << std::endl;
		std::cout << "float:	" << static_cast<float>(single_char) << ".0f" << std::endl;
		std::cout << "double:	" << static_cast<double>(single_char) << ".0" << std::endl;
		return;
	}

	double value = atof(literal.c_str());	//	.c_str() returns a pointer to a string as in a C string. atof() takes that pointer as parameter.

	std::cout << "char:	";
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || !isprint((value)))	// Note that isprint() casts to int by default.
		std::cout << "non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int:	";
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "overflow" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << "float:	";
	if (static_cast<float>(value) == static_cast<int>(value))
		std::cout << static_cast<float>(value) << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(value) << "f" << std::endl;

	std::cout << "double:	";
	if (static_cast<double>(value) == static_cast<int>(value))
		std::cout << static_cast<float>(value) << ".0" << std::endl;
	else
		std::cout << value << std::endl;
}