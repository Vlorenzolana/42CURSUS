/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 08:48:53 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/04/08 19:05:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	//Serializer test;	// Not instantiable.
	Data card;

	card.first_name = "John";
	card.last_name = "Doe";
	card.age = 48;
	card.money = 514.78452;
	card.has_job = true;

	std::cout << std::endl;
	std::cout << "Original data structure:" << std::endl;
	std::cout << card.first_name << " " <<  card.last_name << ", age " << card.age << ", savings " << card.money << ", is employed: " << card.has_job << std::endl;
	std::cout << "Original data address:	" << &card << std::endl;

	std::cout << std::endl;
	uintptr_t serialized_ptr =  Serializer::serialize(&card);
	std::cout << "Testing serialization:	" << serialized_ptr << std::endl;
	
	std::cout << std::endl;
	std::cout << "Testing deserialization:" << std::endl;
	Data *recovered_ptr = Serializer::deserialize(serialized_ptr);
	std::cout << "Recovered data address:	" << recovered_ptr << std::endl;
	//std::cout << "Recovered pointer-to-data address:	" << &recovered_ptr << std::endl;
	std::cout << "Recovered data structure:" << std::endl;
	std::cout << card.first_name << " " <<  card.last_name << ", age " << card.age << ", savings " << card.money << ", is employed: " << card.has_job << std::endl;
	std::cout << std::endl;
	return 0;
}