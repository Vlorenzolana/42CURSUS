/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:38:34 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/04/11 21:03:51 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static void	validateInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];

		if(arg.empty())
			throw std::runtime_error("Error: empty argument.");

		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!std::isdigit(static_cast<unsigned char>(arg[j])))
				throw std::runtime_error("Error: invalid character.");
		}

		long	value = std::strtol(arg.c_str(), NULL, 10);

		if (value < 0)
			throw std::runtime_error("Error: negative numbers are not allowed.");

		if (value > INT_MAX)
			throw std::runtime_error("Error: number out of range.");
	}	
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "./PmergeMe <positive integers>" << std::endl;
		return 1;
	}

	try
	{
		validateInput(argc, argv);

		PmergeMe sorter(argc, argv);
		sorter.runSort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
