/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:38:40 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/04/11 21:03:33 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int	value = std::atoi(argv[i]);
		_dataVec.push_back(value);
		_dataDeq.push_back(value);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : _dataVec(other._dataVec), _dataDeq(other._dataDeq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_dataVec = other._dataVec;
		_dataDeq = other._dataDeq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool	PmergeMe::alreadySorted() const
{
	for (size_t i = 1; i < _dataVec.size(); ++i)
	{
		if (_dataVec[i - 1] > _dataVec[i])
			return false;
	}
	return true;
}

template <typename T>
void	displayConsatiner(const T &container)
{
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
	std::cout << std::endl;	
}

template <typename T>
void	buildInsertionOrder(size_t size, T &sequence)
{
	if (size == 0)
		return ;
	sequence.push_back(0);
	if (size == 1)
		return ;

	size_t	prev = 0;
	size_t	curr = 1;

	while (true)
	{
		size_t	next = curr + 2 * prev;
		if (next >= size)
			break ;
		
		sequence.push_back(next);
		prev = curr;
		curr = next;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
			sequence.push_back(i);
	}
}

template <typename Container>
void	mergeInsertionAlgorithm(Container &input)
{
	if (input.size() <= 1)
		return ;

	Container	largerGroup;
	Container	smallerGroup;

	bool	hasOdd = (input.size() % 2 != 0);
	typename	Container::value_type oddElement;

	if (hasOdd)
		oddElement = input.back();

	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
		{
			largerGroup.push_back(input[i]);
			smallerGroup.push_back(input[i + 1]);
		}
		else
		{
			largerGroup.push_back(input[i + 1]);
			smallerGroup.push_back(input[i]);
		}
	}

	mergeInsertionAlgorithm(largerGroup);

	Container	insertionOrder;
	buildInsertionOrder(smallerGroup.size(), insertionOrder);

	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		size_t	idx = insertionOrder[i];
		typename	Container::iterator pos = std::lower_bound(largerGroup.begin(), largerGroup.end(), smallerGroup[idx]);
		largerGroup.insert(pos, smallerGroup[idx]);
	}

	if (hasOdd)
	{
		typename	Container::iterator pos = std::lower_bound(largerGroup.begin(), largerGroup.end(), oddElement);
		largerGroup.insert(pos, oddElement);
	}

	input = largerGroup;
}

void	PmergeMe::runSort()
{
	if (alreadySorted())
		throw std::runtime_error("Already sorted.");

	std::cout << "Before: ";
	displayConsatiner(_dataVec);

	std::clock_t	starVec = std::clock();
	mergeInsertionAlgorithm(_dataVec);
	std::clock_t	endVec = std::clock();

	std::clock_t	starDeq = std::clock();
	mergeInsertionAlgorithm(_dataDeq);
	std::clock_t	endDeq = std::clock();

	double	timeVec = double(endVec - starVec) / CLOCKS_PER_SEC * 1000;
	double	timeDeq = double(endDeq - starDeq) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
	displayConsatiner(_dataVec);

	std::cout << "Vector time " << timeVec << " ms" << std::endl;
	std::cout << "Deque time " << timeDeq << " ms" << std::endl;
}