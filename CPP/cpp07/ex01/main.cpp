/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:06:53 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/23 16:45:00 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "=== Testing with NON-CONST Arrays ===" << std::endl;
	std::cout << std::endl;

	// Test 1: Integer array
	std::cout << "--- Test 1: Integer Array (printer with const ref) ---" << std::endl;
	int arr_int[] = {0, 1, 2, 3, 4};
	iter(arr_int, 5, printer<int>);
	std::cout << std::endl;

	// Test 2: Character array
	std::cout << "--- Test 2: Character Array ---" << std::endl;
	char arr_char[] = {'a', 'b', 'c', 'd', 'e'};
	iter(arr_char, 5, printer<char>);
	std::cout << std::endl;

	// Test 3: Modify elements with non-const reference
	std::cout << "--- Test 3: Increment integers (non-const ref) ---" << std::endl;
	std::cout << "Before: ";
	iter(arr_int, 5, printer<int>);
	iter(arr_int, 5, incrementer<int>);
	std::cout << "After:  ";
	iter(arr_int, 5, printer<int>);
	std::cout << std::endl;

	// Test 4: Float array
	std::cout << "--- Test 4: Float Array ---" << std::endl;
	float arr_float[] = {1.5f, 2.3f, 3.7f, 4.2f};
	iter(arr_float, 4, printer<float>);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "=== Testing with CONST Arrays ===" << std::endl;
	std::cout << std::endl;

	// Test 5: Const integer array
	std::cout << "--- Test 5: Const Integer Array ---" << std::endl;
	const int arr_const_int[] = {5, 6, 7, 8, 9};
	iter(arr_const_int, 5, printer<const int>);
	std::cout << std::endl;

	// Test 6: Const character array
	std::cout << "--- Test 6: Const Character Array ---" << std::endl;
	const char arr_const_char[] = {'f', 'g', 'h', 'i', 'j'};
	iter(arr_const_char, 5, printer<const char>);
	std::cout << std::endl;

	// Test 7: Double array
	std::cout << "--- Test 7: Double Array ---" << std::endl;
	double arr_double[] = {10.5, 20.3, 30.7, 40.1, 50.9};
	iter(arr_double, 5, printer<double>);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "=== Test Complete ===" << std::endl;
	std::cout << std::endl;

	return 0;
}