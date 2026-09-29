/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:21:04 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	_monton = new std::stack<float>;
	//std::cout << "Switching ON the calculator" << std::endl;
}

RPN::RPN(const RPN& original)
{
	_monton = new std::stack<float>;
	*_monton = *original._monton;
	//std::cout << "Cloning calculator" << std::endl;

}

RPN::~RPN()
{
	delete _monton;
	//std::cout << "Switching OFF the calculator" << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		RPN temp(other);									//	Create a RPN temp as a copy of other.
		std::swap(this->_monton, temp._monton);			//	Swap its contents with this
	}
	return *this;											//	Return this. When temp goes out of scope it is destroyed.
}

void RPN::SolveExpression(const std::string& input)
{
	std::stringstream	ss(input);
	std::string			aux;
	int					number;

	while (ss >> aux)										//	Tokenize input from stream to string
	{
		std::stringstream temp(aux);						//	Attempt to store as int
		if (temp >> number && temp.eof())
		{
			if ( number < 0 || 9 < number)					// Validate: Only 0 to 9
			{
				std::cout << "Error: Only integers 0 to 9" << std::endl;
				return ;
			}
			else
				_monton->push(number);						//	If OK, stack it.
		}
		else if (aux.length() == 1 && std::string("/*-+").find(aux[0]) != std::string::npos)		//	If operator is found
		{
			if (_monton->size() < 2)																//	it needs at least two operands
			{
				std::cout << "Error: Operator '" << aux << "' requires two operands." << std::endl;
				return ;
			}
			float operand1 = _monton->top();	//	Get operator 1
			_monton->pop();						//	pop it
			float operand2 = _monton->top();	// Get operator 2
			_monton->pop();						//	pop it
			float partial = DoTheMath(operand1, operand2, aux[0]);
			_monton->push(partial);				//	push the result to the stack
		}
		else
		{
			std::cout << "Error: Invalid token '" << aux << "'" << std::endl;
			return ;
		}
	}

	if (_monton->top() == std::numeric_limits<float>::infinity() || _monton->top() == -std::numeric_limits<float>::infinity())
	{
		std::cout << "Error: Float overflow detected" << std::endl;		//	Float overflow
		return ;
	}
	if (_monton->size() == 1)					//	ALL OK
		std::cout << "Result: " << _monton->top() << std::endl;
	else if (_monton->empty())					//	Stack is empty: No result
		std::cout << "Error: Empty expression or no final result." << std::endl;
	else										//	Missing operator(s) / Extra operands
		std::cout << "Error: Expression has too many operands (size: " << _monton->size() << ")." << std::endl;
	return ;
}

float	RPN::DoTheMath(float operand1, float operand2, char symbol)
{
	float result = 0;

	if (symbol == '/')
		result = operand2 / operand1;
	else if (symbol == '*')
		result = operand2 * operand1;
	else if (symbol == '-')
		result = operand2 - operand1;
	else
		result = operand2 + operand1;
	return result;
}
