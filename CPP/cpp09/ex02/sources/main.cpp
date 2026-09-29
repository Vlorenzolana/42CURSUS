/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:48:34 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (!validateArguments(argc, argv))
		return 1;
	std::cout << std::endl << "Arguments are correctly formatted" << std::endl << std::endl;
	
	std::vector<int> unsorted = createUnsortedVector(argc, argv);
	showBefore(unsorted);
	PmergeMe FJ(unsorted);
	
	std::cout << std::endl << "Sorting..." << std::endl << std::endl;
	FJ.MergeInsertionSort();
	
	showAfter(FJ.getResult());

	std::cout << std::endl;
	std::cout << "Time to process a range of " << unsorted.size() << " elements with std::vector	" << std::flush;
	std::cout << FJ.getLapseVector() << " ms" << std::endl;
	std::cout << "Time to process a range of " << unsorted.size() << " elements with std::deque		" << std::flush;
	std::cout << FJ.getLapseDeque() << " ms" << std::endl;
	
	return 0;
}