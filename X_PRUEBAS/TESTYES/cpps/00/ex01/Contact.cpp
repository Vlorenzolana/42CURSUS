/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:58 by kabasolo          #+#    #+#             */
/*   Updated: 2024/12/23 15:54:09 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

int	is_blank(std::string line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ')
			return (0);
	return (1);
}

std::string get_field(std::string prompt)
{
	std::string input;

	while (is_blank(input)) 
	{
		system("clear");
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
	}
	return (input);
}

void	Contact::get_data()
{
	_first_name = get_field("First_name:");
	_last_name = get_field("Last_name:"); 
	_nick_name = get_field("Nick_name:");
	_phone_number = get_field("Phone_number:");
	_darkest_secret = get_field("Your_deepest_secret:");
}

std::string cut_string(std::string line)
{
	std::string new_line = line.substr(0, 9);
	if (line.length() > 9)
		new_line[8] = '.';
	else if (line.length() < 9)
		new_line.append(9 - line.length(), ' ');
	return (new_line);
}

void	Contact::show_data_table()
{
	std::cout << "|" << cut_string(_first_name);
	std::cout << "|" << cut_string(_last_name);
	std::cout << "|" << cut_string(_nick_name) << "|" << std::endl;
}
void	Contact::show_all_data()
{
	std::cout << "First_name: " << _first_name << std::endl;
	std::cout << "Last_name: "  << _last_name << std::endl;
	std::cout << "Nick_name: " << _nick_name << std::endl;
	std::cout << "Phone_number: " << _phone_number << std::endl;
	std::cout << "Secret: " << _darkest_secret << "\n" << std::endl;
}
