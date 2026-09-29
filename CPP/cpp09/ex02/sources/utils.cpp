/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:53:45 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	validateArguments(const int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string temp(argv[i]);
		for (std::string::const_iterator it = temp.begin(); it != temp.end() ; it++)
		{
			if (*it < '0' || '9' < *it)
			{
				std::cout << "Error: Only positive integers are accepted" << std::endl;
				return false;
			}
		}
	}
	return true;
}

void	showBefore(const std::vector<int>& unsorted)
{
	std::cout << "BEFORE: ";
	for (std::vector<int>::const_iterator it = unsorted.begin(); it != unsorted.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	showAfter(const std::vector<int>& sorted)
{
	std::cout << "AFTER: ";
	for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::vector<int> createUnsortedVector(const int argc, char** argv)
{
	std::vector<int> unsorted;

	for (int i = 1; i < argc; i++)
	{
		int temp = std::atoi(argv[i]);
		unsorted.push_back(temp);
	}
	return unsorted;
}