/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:04:52 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/09/29 18:48:58 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(unsigned int N) : _N(N), _numbers()
{
}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if(this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if(_numbers.size() >= _N)
		throw std::runtime_error("Not enough numbers");
	_numbers.push_back(number);
}

long long Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	long long minSpan = std::numeric_limits<long long>::max();

	for (size_t i = 1; i < sortedNumbers.size(); i++)
	{
		long long span = static_cast<long long>(sortedNumbers[i]) - 
							static_cast<long long>(sortedNumbers[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

long long Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
		
	long long min = *std::min_element(_numbers.begin(), _numbers.end());
	long long max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}