/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:25:34 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 18:42:24 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
# include <cstdlib>
# define MAX_VAL 750


#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

/* int main(int, char**)
{
	std::cout << "--- Test 1: Empty Array Creation ---" << std::endl;
	Array<int> emptyArray;
	if (emptyArray.getSize() == 0)
	{
		std::cout << "SUCCESS: Created empty array of size 0." << std::endl;
	}
	else
	{
		std::cerr << "FAILURE! This was not expected!" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 2: Standard Functionality ---" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	Array<int> tmp = numbers;
	Array<int> test(tmp);

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "FAILURE: Values in original and mirror arrays do not match!!" << std::endl;
			return 1;
		}
	}
	std::cout << "SUCCESS: Values saved and retrieved correctly." << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test 3: Exception Handling ---" << std::endl;
	try
	{
		numbers[-2] = 0; // Out of bounds and absurd access. Will throw.
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught expected exception for index -2: " << e.what() << std::endl;
	}

	try
	{
		numbers[MAX_VAL] = 0; // Out of bounds access. Will also throw.
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught expected exception for index MAX_VAL: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 4: Char Array Functionality ---" << std::endl;
	Array<char> charArray(5);
	charArray[0] = 'H';
	charArray[1] = 'e';
	charArray[2] = 'l';
	charArray[3] = 'l';
	charArray[4] = 'o';

	Array<char> charCopy = charArray;
	std::cout << "Original char array: ";
	for (size_t i = 0; i < charArray.getSize(); ++i)
	{
		std::cout << charArray[i];
	}
	std::cout << std::endl;

	std::cout << "Copied char array: ";
	for (size_t i = 0; i < charCopy.getSize(); ++i)
	{
		std::cout << charCopy[i];
	}
	std::cout << std::endl;

	if (charArray[0] == charCopy[0] && charArray[4] == charCopy[4])
	{
		std::cout << "SUCCESS: char arrays were successfully copied." << std::endl;
	}
	else
	{
		std::cerr << "FAILURE: char arrays copy failed." << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
		//std::cout << i << " " << numbers[i] << std::endl;
	}
	std::cout << "--- Test 5: Access to elements through index ---" << std::endl;
	std::cout << "Showing element number 3: "  << numbers[3] << std::endl;
	std::cout << "Showing element number 42: "  << numbers[42] << std::endl;
	std::cout << "Showing element number 749: "  << numbers[749] << std::endl;
	std::cout << "Showing element number 369: "  << numbers[369] << std::endl;
	std::cout << "Showing element number 84: "  << numbers[84] << std::endl;

    delete [] mirror;
    return 0;
} */