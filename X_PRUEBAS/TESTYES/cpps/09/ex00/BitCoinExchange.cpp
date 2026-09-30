/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:01:04 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/26 12:04:30 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

const int BitCoinExchange::daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitCoinExchange::BitCoinExchange() {}

BitCoinExchange::BitCoinExchange(const std::string& filename)
{
	std::ifstream infile(filename.c_str());

	if (!infile)
		throw std::runtime_error("Error: could not open file.");
	
	std::string date;
	std::string num;

	std::getline(infile, num);
	
	while (std::getline(infile, date, ',') && std::getline(infile, num))
		_data.insert(std::make_pair(date, std::strtof(num.c_str(), NULL)));
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange& other): _data(other._data) {}

BitCoinExchange::~BitCoinExchange() {}

static bool leapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool checkDate(const std::string& date, const int *daysInMonth)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (0);
	
	std::istringstream ss(date);
	
	int     year, month, day;
	char    sign1, sign2;

	ss >> year >> sign1 >> month >> sign2 >> day;

	if (ss.fail() || sign1 != '-' || sign2 != '-')
		return (0);

	if (month < 1 || month > 12 || day < 1)
		return (0);

	return day <= daysInMonth[month] + leapYear(year) * (month == 2);
}

float&	BitCoinExchange::operator [] (const std::string& date)
{
	if (!checkDate(date, daysInMonth))
		throw std::runtime_error("Error: bad input => " + date);
	if (_data.find(date) == _data.end())
	{
		std::map<std::string, float>::iterator it(_data.lower_bound(date));
		if (it == _data.begin())
			throw std::runtime_error("Error: too old a date.");
		else
			return (_data[(--it)->first]);
	}
	return (_data[date]);
}

BitCoinExchange&	BitCoinExchange::operator = (const BitCoinExchange& other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return (*this);
}
