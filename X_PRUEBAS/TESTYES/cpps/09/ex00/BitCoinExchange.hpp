/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:47 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/25 20:42:01 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>		//
#include <cstdlib>		//std::strtof()
#include <map>			//std::map
#include <fstream>		//std::ifstream

class BitCoinExchange
{
	private:
		std::map<std::string, float>	_data;	// [YYYY-MM-DD]->(float bitCoin value) :D
		static const int				daysInMonth[13];

		BitCoinExchange();

	public:
		BitCoinExchange(const std::string& filename);
		BitCoinExchange(const BitCoinExchange& other);
		~BitCoinExchange();

		float&	operator [] (const std::string& date);
		BitCoinExchange&	operator = (const BitCoinExchange& other);
};

#endif