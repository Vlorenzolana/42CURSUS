/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:00:10 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/04/08 19:05:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

bool	evaluate_shitty_input(const std::string& literal)
{
	bool	has_dot = false;
	bool	has_digit = false;
	
	if (literal.length() == 1 && !isdigit(literal[0]))	// A single non digit is OK. Note that, e.g., input '4' will be treated as 'int 4' not as 'char 52'
		return true;    

	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (isdigit(literal[i]))
			has_digit = true;
		else if (literal[i] == '.')
		{
			if (has_dot)
				return false;		// False if second dot.
			has_dot = true;			// Mark on first dot
		}
		else if (literal[i] == '-' || literal[i] == '+')
		{
			if (i != 0)
				return false;		// Sign must be at the beginning.
		}
		else
			return false;			// Found a char that is not a digit, dot, or sign.
	}
	return has_digit;
}

bool	evaluate_specials(const std::string &literal)
{
	if (literal == "nan" || literal == "inf" || literal == "+inf" || literal == "nanf" || literal == "inff" || literal == "+inff")	// Check for special values.
	{
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;

		if (literal == "nan")
		{
			std::cout << "float:	" << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;	// std::numeric_limits: A template class defined in the <limits> header. It provides info about properties of primitives like int, float, and double. 
			std::cout << "double:	" << std::numeric_limits<double>::quiet_NaN() << std::endl;		// ::quiet_NaN(): A static member function of the numeric_limits class. Returns a NaN (Not a Number) value for the specified type (double in this case). A "quiet" NaN is one that doesn't cause crashes or exceptions. Used to represent the result of an undefined operation such as dividing zero by zero.
		}
		else
		{
			std::cout << "float:	" << std::numeric_limits<float>::infinity() << "f" << std::endl;	// ::infinity() A static member function from the <limits> header. It returns the standardized value for positive infinity for the data type (float in this case). 1.0f / 0.0f would result in this value.
			std::cout << "double:	" << std::numeric_limits<double>::infinity() << std::endl;
		}
		return true;
	}
	else if (literal == "-nan" || literal == "-inf" || literal == "-nanf" || literal == "-inff")	// Check for negative special values.
	{
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;

		if (literal == "-nan" || literal == "-nanf")
		{
			std::cout << "float:	" << -std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
			std::cout << "double:	" << -std::numeric_limits<double>::quiet_NaN() << std::endl;
		}
		else
		{
			std::cout << "float:	" << -std::numeric_limits<float>::infinity() << "f" << std::endl;
			std::cout << "double:	" << -std::numeric_limits<double>::infinity() << std::endl;
		}
		return true;
	}
	else
		return false;
}

int	main(int argc, char **argv)
{
	//ScalarConverter object;		// NOT INSTANTIABLE
	
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl << "Usage: ./convert <arg1>" << std::endl;
		return 1;
	}	
	std::string literal = argv[1];
	if (evaluate_specials(literal))
		return 0;
	if (!evaluate_shitty_input(literal))
	{
		std::cout << "Error" << std::endl << "Shitty input detected" << std::endl;
		return 1;
	}
	ScalarConverter::convert(literal);	
	return 0;
}