/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:52:59 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& input)
{
	_vec = std::vector<int>(input.begin(), input.end());
	_deq = std::deque<int>(input.begin(), input.end());
	_lapseVector = 0;
	_lapseDeque = 0;
	
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& original)
{
	_vec = original._vec;
	_deq = original._deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		PmergeMe temp(other);					//	Create temp with copy constructor
		std::swap(this->_vec, temp._vec);		//	Swap contents of vector
		std::swap(this->_deq, temp._deq);		//	Swap contents of deque
	}						
	return *this;								//	And return. Temp is destroyed when it goes out of scope.
}

void	PmergeMe::MergeInsertionSort()
{
	MIS(_vec, _lapseVector);
	MIS(_deq, _lapseDeque);
}

std::vector<int>	PmergeMe::getResult()
{
	return _vec;
}

double PmergeMe::getLapseVector() const
{
	return _lapseVector;
}

double PmergeMe::getLapseDeque() const
{
	return _lapseDeque;
}

