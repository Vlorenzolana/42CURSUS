/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:32:29 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/18 11:32:30 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

bool	isChar(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool	isInt(const std::string &str)
{
	char	*end;
	errno = 0;
	std::strtol(str.c_str(), &end, 10);
	if (*end != '\0')
		return false;
	if (errno == ERANGE)
		return false;
	return true;
}

bool	isFloat(const std::string &str)
{
	if (str[str.length() - 1] != 'f')
		return false;
	std::string tmp = str.substr(0, str.length() - 1);
	char	*end;
	errno = 0;

	std::strtod(tmp.c_str(), &end);
	if (*end != '\0')
		return false;
	return true;
}

bool	isDouble(const std::string &str)
{
	char	*end;
	errno = 0;
	std::strtod(str.c_str(), &end);
	if (*end != '\0')
		return false;
	return true;
}

bool	isSpecial(const std::string &str)
{
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" ||
			str == "+inff" || str == "-inff");
}