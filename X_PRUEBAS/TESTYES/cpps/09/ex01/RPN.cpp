/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:04:27 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/16 17:55:57 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other): _stack(other._stack) {}

RPN::~RPN() {}

void RPN::add(char input)
{
	int	num1;
	int	num2;

	if (isdigit(input))
		return (_stack.push(input - '0'));

	if (isspace(input))
		return ;

	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	num1 = _stack.top();
	_stack.pop();
	num2 = _stack.top();
	_stack.pop();

	switch (input)
	{
		case '+':
			return(_stack.push(num2 + num1));
		case '-':
			return(_stack.push(num2 - num1));
		case '*':
			return(_stack.push(num2 * num1));
		case '/':
			if (num1 == 0)
				throw std::runtime_error("Error: tried dividing by 0");
			return(_stack.push(num2 / num1));
		default:
			throw std::runtime_error("Error");
	}
}

int RPN::getRes()
{
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}

RPN&	RPN::operator = (const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}
