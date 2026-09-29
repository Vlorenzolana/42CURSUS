/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:38:47 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/09 13:18:33 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	Oian("Oian", 120);
		std::cout << Oian << std::endl;

		for (int i = 0; i < 40 ; i++)
		{
			Oian.decrementGrade();
			std::cout << Oian << std::endl;
		
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
}