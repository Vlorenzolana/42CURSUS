/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:58:07 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/06 11:28:51 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;

	_rawNum = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;

	_rawNum = num << _fractionalBit;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;

	_rawNum = roundf(num * (1 << _fractionalBit));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator = (const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_rawNum = other.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	_rawNum = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_rawNum);
}

float	Fixed::toFloat(void) const
{
	return (_rawNum + 0.0f) / (1 << _fractionalBit);
}

int	Fixed::toInt(void) const
{
	return _rawNum >> _fractionalBit;
}

std::ostream&	operator << (std::ostream &num, const Fixed& other)
{
	return (num << other.toFloat());
}
