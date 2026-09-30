/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:36:07 by kabasolo          #+#    #+#             */
/*   Updated: 2025/05/13 13:30:15 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <cstdlib>
#include <ctime>

int main(void)
{
    Span nums(100000);
    std::srand(std::time(0));

    try
    {
        while (1)
            nums.addNumber(std::rand());
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

	try
	{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << nums.longestSpan() << std::endl;
		std::cout << nums.shortestSpan() << std::endl;

		Span sp = Span(5);
		sp.addNumber(-1);
		sp.addNumber(9);
		sp.addNumber(4);
		std::cout << "---------------------------------------" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		Span cpy(sp);
		cpy.addNumber(90);
		std::cout << "---------------------------------------" << std::endl;
		std::cout << cpy.shortestSpan() << std::endl;
		std::cout << cpy.longestSpan() << std::endl;

		Span cpy2 = sp;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << cpy2.shortestSpan() << std::endl;
		std::cout << cpy2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}