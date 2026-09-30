/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:47:13 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/24 17:44:38 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"


int main()
{
	
	Data		data;
	Data		*ptr = &data;
	uintptr_t	uptr = Serializer::serialize(&data);

	data.id = 1;
	data.name = "aaaa";
	data.writter = "me";

	std::cout << HBLU;

	std::cout << data.id << std::endl;
	std::cout << data.name << std::endl;
	std::cout << data.writter << std::endl;

	std::cout << HGRE;

	std::cout << ptr->id << std::endl;
	std::cout << ptr->name << std::endl;
	std::cout << ptr->writter << std::endl;

	ptr = Serializer::deserialize(uptr);

	std::cout << HMAG;

	std::cout << ptr->id << std::endl;
	std::cout << ptr->name << std::endl;
	std::cout << ptr->writter << std::endl;

	std::cout << RST;

	return 0;
}