/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:14:18 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/28 20:30:57 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}

int Phonebook::add_contact(std::string input)
{
	Contact		newcontact;
	static int	indexcontact = 0;

	(void)input;
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	std::cout << "Enter your first name\n";
	std::cin >> firstname;
	newcontact.set_first_name(firstname);
	std::cout << "Enter your last name\n";
	std::cin >> lastname;
	newcontact.set_last_name(lastname);
	std::cout << "Enter your nickname\n";
	std::cin >> nickname;
	newcontact.set_nickname(nickname);
	std::cout << "Enter your phonenumber\n";
	std::cin >> phone_number;
	newcontact.set_phone_number(phone_number);
	std::cout << "Enter your darkest secret\n";
	std::cin >> darkest_secret;
	newcontact.set_darksecret(darkest_secret);
	_phonebook[indexcontact] = newcontact;
	indexcontact = (indexcontact + 1) % MAX_CONTACTS; // 7 -> 0
	std::cout << "contact has been added successfully\n\n";
	return (1);
}

static std::string format_column(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	std::string result = str;
	// pad left until width 10 (right-aligned)
	while (result.length() < 10)
		result = " " + result;
	return (result);
}

int Phonebook::search_contact(std::string input)
{
	int	i;
	int	index;

	(void)input;
	std::cout << "|   Index  |First Name| Last Name| Nickname |\n";
	std::cout << "---------------------------------------------\n";
	i = 0;
	while (i < MAX_CONTACTS)
	{
		if (!_phonebook[i].get_first_name().empty())
		{
			std::cout << "|" << std::setw(10) << std::right << i << "|" << format_column(_phonebook[i].get_first_name()) << "|" << format_column(_phonebook[i].get_last_name()) << "|" << format_column(_phonebook[i].get_nickname()) << "|\n";
		}
		i++;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "Enter the index of the contact to display: ";
	std::cin >> index;
	if (std::cin.fail() || index < 0 || index >= MAX_CONTACTS
		|| _phonebook[index].get_first_name().empty())
	{
		std::cin.clear();
		std::cout << "Invalid index. No contact found.\n\n\n";
		return (1);
	}
	std::cout << "First Name: " << _phonebook[index].get_first_name() << "\n";
	std::cout << "Last  Name: " << _phonebook[index].get_last_name() << "\n";
	std::cout << "Nickname: " << _phonebook[index].get_nickname() << "\n";
	std::cout << "Phone Number: " << _phonebook[index].get_number_phone() << "\n";
	std::cout << "Darkest Secret: " << _phonebook[index].get_darksecret() << "\n\n";
	return (0);
}

/*
En UFT-8, un caracter ASCII ocupa 1 byte y la 'ñ' 2 bytes, en cambio,
en UFT-16 ambos ocupan 2 bytes.

std::string: Almacena cadenas en formato estándar de bytes (como UTF-8).
Cada elemento de un std::string es un char, que tiene un tamaño de 1 byte.
Esto significa que caracteres como ñ ocupan varios elementos en la cadena.

std::wstring: Almacena cadenas en un formato ancho.
Cada elemento de un std::wstring es un wchar_t,
	que tiene un tamaño mayor (2 bytes en Windows, 4 bytes en Linux).
Esto permite que caracteres como ñ se almacenen como un único elemento,
	sin importar si ocupan 2 o 4 bytes.*/
