/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:23:11 by kabasolo          #+#    #+#             */
/*   Updated: 2024/12/26 15:29:13 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook(){
	max = 0;
	i = 0;
}

Phonebook::~Phonebook(){}

static int	is_blank(std::string line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ')
			return (0);
	return (1);
}

static void	wait_enter()
{
	std::string input;
	std::cout << "Press enter to continue... ";
	std::getline(std::cin, input);
}

static bool	is_numeric(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
		if (!std::isdigit(*it)) 
			return (0);
	return (1);
}

void	Phonebook::add_contact()
{
	system("clear");
	_contacts[i++].get_data();
	max += (max < 8);
	i *= (i < 8);
}

void	Phonebook::search_contact()
{
	std::string	input;
	int			n;

	if (max == 0)
		return ;
	while (is_blank(input) || !is_numeric(input) || !(std::atoi(input.c_str()) >= 0 && std::atoi(input.c_str()) < max))
	{
		system("clear");
		std::cout << "-----------------------------------------" << std::endl;
		n = 0;
		while (n < max)
		{
			std::cout << "|    " << n << "    ";
			_contacts[n++].show_data_table();
		}
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Type index: ";
		std::getline(std::cin, input);
	}
	system("clear");
	_contacts[std::atoi(input.c_str())].show_all_data();
	wait_enter();
}
