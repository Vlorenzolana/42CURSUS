/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:01:17 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/09 18:32:46 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	header()
{
	system("clear");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|         < Here is my Phonebook! >         |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "| *ADD:    add a new contact                |" << std::endl;
	std::cout << "| *SEARCH: display the info about a contact |" << std::endl;	
	std::cout << "| *EXIT:   end the program (not cool) >:(   |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

int main(void)
{
	Phonebook book;
	std::string input;

	while (1)
	{
		header();
		std::getline(std::cin, input);
		if(input == "EXIT")
			break;
		else if(input == "ADD")
			book.add_contact();
		else if(input == "SEARCH")
			book.search_contact();
	}
	return (0);
}

