/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:36:58 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/18 19:36:59 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Charlie", 1);
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

    try
	{
		Bureaucrat d("Dave", 150);
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

