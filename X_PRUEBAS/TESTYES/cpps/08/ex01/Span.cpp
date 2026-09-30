/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:40:36 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/20 18:41:38 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _nums(), _size(0) {}

Span::Span(unsigned int n): _size(n) {_nums.reserve(n);}

Span::Span(const Span& other): _nums(other._nums), _size(other._size) {}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_nums.size() >= _size)
		throw std::runtime_error("Span is full, cannot add more numbers.");
	_nums.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (_nums.size() < 2)
			throw std::runtime_error("Not enough numbers to find a span.");

	std::vector<int> sorted(_nums);
	std::sort(sorted.begin(), sorted.end());

	unsigned int diff = UINT_MAX;

	for(long unsigned int i = 0; i < sorted.size() - 1; i ++)
	{
		unsigned int tempDiff = sorted[i + 1] - sorted[i];
		if (tempDiff < diff)
			diff = tempDiff;
	}
	return (diff);
}

unsigned int Span::longestSpan()
{
	if (_nums.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span.");

	int	small = INT_MAX;
	int	big = INT_MIN;

	for(long unsigned int i = 0; i < _nums.size(); i ++)
	{
		if (small > _nums[i])
			small = _nums[i];
		if (big < _nums[i])
			big = _nums[i];
	}
	return (big - small);
}

Span&	Span::operator = (const Span& other)
{
	if (this != &other)
	{
		_size = other._size;
		_nums = other._nums;
	}
	return (*this);
}
