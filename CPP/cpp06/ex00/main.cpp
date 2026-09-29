/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:00:10 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/20 16:58:16 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

bool	evaluate_novalid_input(const std::string& literal)
{
	if (literal.empty())
		return false;
	if (literal.length() == 1 && !isdigit(literal[0]))	// A single non digit is OK. Note that, e.g., input '4' will be treated as 'int 4' not as 'char 52'
		return true;

	bool	has_dot = false;
	bool	has_digit = false;
	size_t	end = literal.length();

	// Accept trailing 'f' only if there is a decimal point (float literal like 42.0f)
	if (literal[end - 1] == 'f')
	{
		if (literal.find('.') == std::string::npos)
			return false;
		--end;
	}

	for (size_t i = 0; i < end; ++i)
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
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;
		std::cout << "float:	nanf" << std::endl;
		std::cout << "double:	nan" << std::endl;
		return true;
	}
	if (literal == "+inf" || literal == "inf" || literal == "+inff" || literal == "inff")
	{
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;
		std::cout << "float:	+inff" << std::endl;
		std::cout << "double:	+inf" << std::endl;
		return true;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char:	impossible" << std::endl;
		std::cout << "int:	impossible" << std::endl;
		std::cout << "float:	-inff" << std::endl;
		std::cout << "double:	-inf" << std::endl;
		return true;
	}
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
	if (!evaluate_novalid_input(literal))
	{
		std::cerr << "Error" << std::endl << "Invalid input" << std::endl;
		return 1;
	}
	ScalarConverter::convert(literal);
	return 0;
}