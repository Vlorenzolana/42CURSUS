/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:25:26 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/30 19:22:35 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed& model)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = model._value;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	_value = number << _fbits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	float scale_factor = (1 << _fbits);
	_value = static_cast<int>(number * scale_factor);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    float scale_factor = (1 << _fbits);
    return (static_cast<float>(_value) / scale_factor);
}

int Fixed::toInt(void) const
{
    return (_value >> _fbits); 
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_value = other._value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits getter function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits setter function called" << std::endl;
	_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_obj)
{
    os << fixed_obj.toFloat();			//	Convert the fixed_obj to its float representation using the toFloat() method, then insert it into the output stream.
    return (os); 						//	Return the stream to allow for chaining
}
