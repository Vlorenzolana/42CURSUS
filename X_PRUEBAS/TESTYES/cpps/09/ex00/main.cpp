/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:50:02 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/26 13:41:18 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"
#include <cmath>

static float howManyBitCoins(std::string line)
{
	if (line.size() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
			throw std::runtime_error("Error: syntax error");
	
		std::string valueStr = line.substr(13);

		char* endptr;
		float f = std::strtof(valueStr.c_str(), &endptr);
	
		if (endptr[0] != '\0' && endptr[0] != '\n')
			throw std::runtime_error("Error: syntax error");

		if (std::isnan(f))
			throw std::runtime_error("Error: nanf");

		if (f < 0)
			throw std::runtime_error("Error: not a positive number");

		if (f >= 2147483648)
			throw std::runtime_error("Error: to large a number");

		return (f);
}

static void checkBitCoin(BitCoinExchange& bitData, std::string line)
{
	try
	{
		std::string date = line.substr(0, 10);
	
		float bitValue = bitData[date];
		float bitQuantity = howManyBitCoins(line);
	
		std::cout << date << " => " << bitQuantity << " = " << bitQuantity * bitValue << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static bool firstCheck(int argc, std::ifstream& infile)
{
	std::string	line;

	if (argc > 2)
		return (std::cout << "Error: to many arguments." << std::endl, 0);
	
	if (!infile)
		return (std::cout << "Error: could not open file." << std::endl, 0);
	
	if (std::getline(infile, line, '\n') && line != "date | value")
		return (std::cout << "Error: non valid format." << std::endl, 0);

	return (1);
}

int main(int argc, char **argv)
{
	std::ifstream	infile(argv[1]);
	std::string		line;
	
	if (!firstCheck(argc, infile))
		return (1);

	BitCoinExchange	bitData("data.csv");

	while (std::getline(infile, line))
		checkBitCoin(bitData, line);

	return (0);
}
