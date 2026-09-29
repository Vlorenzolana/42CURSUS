/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:50:20 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 12:50:23 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Setting up exchange" << std::endl;
	_exchange_rates = new std::map<std::string, float>;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& original)
{
	std::cout << "Copying exchange..." << std::endl;
	_exchange_rates = new std::map<std::string, float>();
	*_exchange_rates = *original._exchange_rates;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Eliminating exchange" << std::endl;
	delete _exchange_rates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		delete _exchange_rates;
		_exchange_rates = new std::map<std::string, float>;
		*_exchange_rates = *other._exchange_rates;
	}
	return *this;
}

void BitcoinExchange::getHistoricRecords()
{
	std::string line;							//	One...
	std::string	date_str;						//	two...
	std::string	value_str;						//	and three buffers.
	float		value;

	std::ifstream historicRecords("data.csv");
	if (!historicRecords.is_open())
		throw std::runtime_error("Runtime Error: Cannot open data.csv file");

	std::getline(historicRecords, line);			//	Read and discard the header line storing it in 'line' buffer

	while (std::getline(historicRecords, line))		//	Read and process the remaining lines storing them in 'line' buffer: Overwrite previous lines.
	{
 		std::stringstream ss(line);				//	Instantiate an std::stringstream object to store the line just read.
		std::getline(ss, date_str, ',');		//	Read it to the ',' and store it in date_str.
		std::getline(ss, value_str);			//	Read to the end and store it in value_str.
		std::stringstream tmp(value_str);		//	Pass value_str to stringstream,
		tmp >> value;							//	And insert it into float value.
		addRecord(date_str, value);				//	Pass data to be stored to helper function
	}
	historicRecords.close();					//	No leaks!
}

void	BitcoinExchange::addRecord(const std::string& date_str, const float& value)
{
	this->_exchange_rates->insert(std::pair<const std::string, const float>(date_str, value));	//	Store data in container.
}

float	BitcoinExchange::LookUpRecord(const std::string& date)									//	Get data from container
{
	std::map<std::string, float>::iterator it = _exchange_rates->find(date);
	if (it != _exchange_rates->end())
	{
		return it->second;
	}
	return 0;
}

std::string BitcoinExchange::LookUpDate(std::string& date)
{
    std::map<std::string, float>::iterator it = _exchange_rates->lower_bound(date);	//	Lower bound = "not less than 'date'"


    if (it != _exchange_rates->end() && it->first == date)							//	Case 1: Exact match. Just return it.
        return it->first;
    if (it == _exchange_rates->begin())												//	Case 2: No previous date. Return an empty string.
        return ""; 
    --it; 																			//	Case 3: Iterate once backwards and return.
    return it->first;
}


