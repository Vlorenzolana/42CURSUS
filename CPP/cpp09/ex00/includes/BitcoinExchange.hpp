/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:50:06 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 12:50:10 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>			//	Printing
#include <map>				//	Container
#include <fstream>			//	Read/Write file
#include <string>			//	String manipulation
#include <sstream>			//	Stream ops for parsing and formatting
#include <exception>		//	Basic exceptions
#include <ctime>			//	Date validation
#include <cstring>			//	Parsing
#include <limits>			//	Other validations


class BitcoinExchange
{
	private:
		std::map<std::string, float> *_exchange_rates;
	
	protected:

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& original);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	getHistoricRecords();
		void	addRecord(const std::string& date_str, const float& value);
		float	LookUpRecord(const std::string& date);
		std::string LookUpDate(std::string& date);
};
