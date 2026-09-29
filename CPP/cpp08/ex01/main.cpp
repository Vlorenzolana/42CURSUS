/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:24:38 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 11:24:41 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

void	testSpan(Span& sp, const std::string& name, unsigned int num_to_add)
{
	std::cout << "--- Testing " << name << " ---" << std::endl;

	try
	{
		std::cout << "Attempting to add " << num_to_add << " numbers..." << std::endl;
		sp.addManyNumbers(num_to_add);
		std::cout << "Successfully added " << num_to_add << " numbers." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Calculating spans..." << std::endl;
		int s = sp.shortestSpan();
		int l = sp.longestSpan();
		std::cout << "Shortest span: " << s << std::endl;
		std::cout << "Longest span: " << l << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception while calculating spans: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main()
{
	srand(static_cast<unsigned int>(time(0)));

	int		elements = 10;		//	For tests
	Span	default_span;
	Span	custom_span(elements);
	Span	empty_span(5);

	std::cout << std::endl;
	testSpan(default_span, "Default Span", 5);
	testSpan(custom_span, "Custom Span", elements);

	std::cout  << "--- Testing `vectorIsFullException` on Default Span ---" << std::endl;
	try
	{
		std::cout << "Attempting to add one more number..." << std::endl;
		default_span.addNumber(12345);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Testing `vectorIsFullException` on Custom Span ---" << std::endl;
	try
	{
		std::cout << "Attempting to add one more number..." << std::endl;
		custom_span.addNumber(42);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Testing `vectorIsEmptyException` ---" << std::endl;
	try
	{
		std::cout << "Attempting to find span on an empty vector..." << std::endl;
		empty_span.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Filling empty_span from another container..." << std::endl;
	std::vector<int> test_vector;	//	Create a source vector to test this shit.
	test_vector.push_back(1);		//	Fill it with some novalid values.
	test_vector.push_back(5);
	test_vector.push_back(3);
	test_vector.push_back(43);
	test_vector.push_back(5);

	try
	{
		for (std::vector<int>::iterator test_it = test_vector.begin(); test_it != test_vector.end(); test_it++)
			empty_span.addNumber(*test_it);	//	Read those values dereferencing the iterator and call addNumber with them.
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;	//	This is not expected.
	}
	std::cout << std::endl;

	testSpan(empty_span, "Not-so-empty Span", 1);	//	Exception will happen when attempting to add another number.

	return 0;
}
