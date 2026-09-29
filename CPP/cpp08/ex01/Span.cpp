/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:23:35 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 11:23:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(): _size(5), _filled(0), _vctr(5)
{
	std::cout << "Default Span object with a "<< _size << "-element vector created" << std::endl;
	return ;
	//	Watch out here: Vector elements are initialized to 0. This is the C++ way of creating a vector. In function addNumber we must overwrite not initialize.
}

Span::Span(unsigned int n): _size(n), _filled(0), _vctr(n)
{
	std::cout << "Custom Span object with a " << _size << "-element vector created" << std::endl;
	return ;
	//	See comment above.
}

Span::Span(const Span& original)
{
	_vctr = original._vctr;
	return ;
}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
	_size = other._size;
	_filled = other._filled;
	_vctr = other._vctr;
	return *this;	
}

void	Span::addNumber(const int number)
{
	if (_filled < _size)
	{
		_vctr[_filled] = number;	// See comment at constructors.
		_filled++;
	}
	else
		throw Span::vectorIsFullException();
}

void	Span::addManyNumbers(int manyNumbers)
{
	for (int i = 1; i <= manyNumbers; i++)
	{
		int z = rand();
		addNumber(z);
		std::cout << z << std::endl;
	}
}

int	Span::shortestSpan()
{
	int	shortest = std::numeric_limits<int>::max();
	
	if (_filled < 2)
		throw Span::vectorIsEmptyException();
		
	std::sort(_vctr.begin(), _vctr.end());
	
    for (std::vector<int>::iterator it = _vctr.begin(); it != _vctr.end() - 1; ++it)
    {
        int result = *(it + 1) - *it;
        if (result < shortest)
            shortest = result;
    }
	
	return shortest;
}

int	Span::longestSpan()
{
	if (_filled < 2)
		throw Span::vectorIsEmptyException();
		
	std::sort(_vctr.begin(), _vctr.end());
	
	return _vctr.back() - _vctr.front();
}

const char* Span::vectorIsFullException::what() const throw()
{
	return ("Exception: Vector is full. Cannot add new elements");
}

const char* Span::vectorIsEmptyException::what() const throw() 
{
	return ("Exception: No span to measure");
}
