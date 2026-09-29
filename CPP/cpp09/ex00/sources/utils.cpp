/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:16:23 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*	Parses and validates a date string, trims spaces and tabs */
bool checkDate(std::string& date_str)
{
	std::string::size_type first = 0;
	std::string::size_type last = date_str.length();
	
	while (first < date_str.length() && (date_str[first] == ' ' || date_str[first] == '\t'))
		first++;
	if (first > 0)
		date_str.erase(0, first);
	while (last > 0 && (date_str[last - 1] == ' ' || date_str[last - 1] == '\t'))
		last--;
	if (last < date_str.length())
		date_str.erase(last);

	int year, month, day;
	char dash1, dash2;

	std::istringstream ss(date_str);    				// Use stringstream
	ss >> year >> dash1 >> month >> dash2 >> day;		// AWESOME STRINGSTREAM attempts to insert the longest sequence possible matching the var type to store into, then advances pointer one position.
	if (ss.fail() || dash1 != '-' || dash2 != '-')						// Validate format
		return false;
	if (year < 2009 || (year == 2009 && month == 1 && day == 1))		//	Validate earliest date
		return false;
	if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)	//	Validate values
		return false;

	std::tm t;
	std::memset(&t, 0, sizeof(std::tm));
	t.tm_year = year - 1900;	//	tm_year is years since 1900.
	t.tm_mon = month - 1;		//	tm_mon is months since January (0-11).
	t.tm_mday = day;			//	tm_mday is day of the month (1-31).
	t.tm_hour = 0;				//	Clear other fields to ensure mktime is operating on the date only
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = -1;			//	DST = Daylights savings time.
	if (std::mktime(&t) == (time_t)-1)		//	Validate again.
		return false;

	return (t.tm_year == (year - 1900) && t.tm_mon == (month - 1) && t.tm_mday == day);
}

/*	Validates koins_str and trims ir from spaces and tabs */
float checkKoins(std::string& koins_str)
{
	float koins;
	std::string::size_type first = 0;
	std::string::size_type last = koins_str.length();

	while (first < koins_str.length() && (koins_str[first] == ' ' || koins_str[first] == '\t'))
		first++;
	if (first > 0)
	koins_str.erase(0, first);
	while (last > 0 && (koins_str[last - 1] == ' ' || koins_str[last - 1] == '\t'))
		last--;
	if (last < koins_str.length())
	koins_str.erase(last);
	std::stringstream ss(koins_str);
	ss >> koins;
	if (ss.fail() || koins < 0 || koins >= std::numeric_limits<int>::max())
		return -1;
	return koins;
}