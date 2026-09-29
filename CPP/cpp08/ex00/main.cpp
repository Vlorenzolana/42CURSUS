/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:23:00 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 11:23:03 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int>			numbers;
	std::vector<std::string>	words;
	int							target_number;
	std::string					target_word;
	size_t						index;
	
	std::cout << std::endl;
	std::cout << "--- Testing an INT vector ---" << std::endl;
	numbers.push_back(0);
	numbers.push_back(654);
	numbers.push_back(24);
	numbers.push_back(73);
	numbers.push_back(4447);
	numbers.push_back(554545);
	numbers.push_back(42);
	numbers.push_back(55);
	numbers.push_back(987);
	numbers.push_back(120);
    
	std::cout << "Vector 'numbers' stores " << int(numbers.size()) << " elements." << std::endl;

    try
	{
		target_number = 42;
		std::cout <<"Searching value: " << target_number << " ..." << std::endl;
        index = easyfind(numbers, target_number);
        std::cout << "The value '" << target_number << "' was found at index " << index << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    try
	{
		target_number = 69;
		std::cout <<"Searching value: " << target_number << " ..." << std::endl;
        index = easyfind(numbers, target_number);
        std::cout << "The value '" << target_number << "' was found at index " << index << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "--- Testing a STRING vector ---" << std::endl;
	words.push_back("Hello");
	words.push_back("there");
	words.push_back("General");
	words.push_back("Kenobi");

	std::cout << "Vector 'words' stores " << int(words.size()) << " elements." << std::endl;

	try
	{
		target_word = "Kenobi";
		std::cout <<"Searching word: " << target_word << " ..." << std::endl;
        index = easyfind(words, target_word);
        std::cout << "The value '" << target_word << "' was found at index " << index << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    try
	{
		target_word = "Grievous";
		std::cout <<"Searching word: " << target_word << " ..." << std::endl;
        index = easyfind(words, target_word);
        std::cout << "The value '" << target_word << "' was found at index " << index << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }
	
	std::cout << std::endl;
    return 0;
}