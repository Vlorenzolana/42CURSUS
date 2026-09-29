/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:31:59 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/18 11:32:02 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <cerrno>


class ScalarConverter
{
	private:
	    ScalarConverter();
	    ScalarConverter(const ScalarConverter &src);
	    ~ScalarConverter();
	    ScalarConverter &operator=(const ScalarConverter &rhs);

	public:
	    static void convert(const std::string &str);
};

bool	isChar(const std::string &str);
bool	isInt(const std::string &str);
bool	isFloat(const std::string &str);
bool	isDouble(const std::string &str);
bool	isSpecial(const std::string &str);
void	printSpecial(const std::string &str);
void	printFromDouble(double value);


#endif
