/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:01:15 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/03/23 17:51:50 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	(void) &other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

bool	RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int		RPN::applyOperation(int a, int b, const std::string &op) const
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("division by zero");
		return a / b;
	}
	throw std::runtime_error("invalid operator");
}

int		RPN::evaluate(const std::string &expr) const
{
	std::stack<int>		s;
	std::stringstream	ss(expr);
	std::string			token;

	while (ss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			s.push(token[0] - '0');
		else if (isOperator(token))
		{
			if (s.size() < 2)
				throw  std::runtime_error("invalid expression");

			int	b = s.top();
			s.pop();
			int	a = s.top();
			s.pop();

			s.push(applyOperation(a, b, token));
		}
		else
			throw std::runtime_error("invalid token");
	}
	if (s.size() != 1)
		throw std::runtime_error("invalid expression");

	return s.top();
}
