/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:41:22 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/04/02 16:42:34 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	a("Alice", 50);
		Form		f("TaxForm", 50, 25);

		std::cout << a << std::endl;
		std::cout << f << std::endl;

		a.signForm(f);

		std::cout << "After signing attempt:" << std::endl;
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;

	try
	{
		Bureaucrat	b("Bob", 100);
		Form		f2("SecretForm", 50, 10);

		std::cout << b << std::endl;
		std::cout << f2 << std::endl;

		b.signForm(f2);

		std::cout << "After signing attempt:" << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;

	try
	{
		Form bad("BadForm", -1, 10);
		std::cout << bad << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
