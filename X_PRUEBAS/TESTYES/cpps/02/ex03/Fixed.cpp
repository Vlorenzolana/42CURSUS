/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:58:07 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/06 12:40:47 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//---------------------------------------------------------------------------//
//   CONSTRUCTORS // DESTRUCTORS                                             //
//---------------------------------------------------------------------------//

Fixed::Fixed(){_rawNum = 0;}

Fixed::Fixed(const Fixed& other) {*this = other;}

Fixed::Fixed(const float num)
{
	_rawNum = roundf(num * (1 << _fractionalBit));
}

Fixed::Fixed(const int num)
{
	_rawNum = num << _fractionalBit;
}

Fixed::~Fixed(){}

//---------------------------------------------------------------------------//
//   COMPARISONS                                                             //
//---------------------------------------------------------------------------//

bool	Fixed::operator >  (const Fixed& other)	{ return (_rawNum >  other._rawNum); }
bool	Fixed::operator <  (const Fixed& other)	{ return (_rawNum <  other._rawNum); }
bool	Fixed::operator >= (const Fixed& other)	{ return (_rawNum >= other._rawNum); }
bool	Fixed::operator <= (const Fixed& other)	{ return (_rawNum <= other._rawNum); }
bool	Fixed::operator == (const Fixed& other)	{ return (_rawNum == other._rawNum); }
bool	Fixed::operator != (const Fixed& other)	{ return (_rawNum != other._rawNum); }

//---------------------------------------------------------------------------//
//   ARITHMETICS                                                             //
//---------------------------------------------------------------------------//

Fixed&	Fixed::operator = (const Fixed& other)
{
	if (this != &other)
		_rawNum = other._rawNum;
	return (*this);
}

Fixed	Fixed::operator + (const Fixed& other)
{
	Fixed	a;
	a.setRawBits(_rawNum + other._rawNum);
	return a;
}

Fixed	Fixed::operator - (const Fixed& other)
{
	Fixed	a;
	a.setRawBits(_rawNum - other._rawNum);
	return a;
}

Fixed	Fixed::operator * (const Fixed& other)
{
	Fixed	a;
	a.setRawBits((_rawNum * other._rawNum) >> _fractionalBit);
	return a;
}

Fixed	Fixed::operator / (const Fixed& other)
{
	if (other._rawNum == 0)
		return Fixed();
	Fixed	a;
	a.setRawBits((_rawNum << _fractionalBit) / other._rawNum);
	return a;
}

//---------------------------------------------------------------------------//
//   INCREMENT // DECREMENT                                                  //
//---------------------------------------------------------------------------//

Fixed	Fixed::operator++()		{ _rawNum ++; return *this; } //Pre-increment
Fixed	Fixed::operator--()		{ _rawNum --; return *this; } //Pre-increment
Fixed	Fixed::operator++(int)	{ Fixed	tmp(*this); _rawNum ++; return (tmp); } //Post-increment
Fixed	Fixed::operator--(int)	{ Fixed	tmp(*this); _rawNum --; return (tmp); } //Post-increment

//---------------------------------------------------------------------------//
//   MIN // MAX                                                              //
//---------------------------------------------------------------------------//

Fixed&	Fixed::min(Fixed& one, Fixed& two)
{
	if (one._rawNum > two._rawNum)
		return (two);
	return (one);
}

const Fixed&	Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one._rawNum > two._rawNum)
		return (two);
	return (one);
}

Fixed&	Fixed::max(Fixed& one, Fixed& two)
{
	if (one._rawNum < two._rawNum)
		return (two);
	return (one);
}

const Fixed&	Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one._rawNum < two._rawNum)
		return (two);
	return (one);
}

//---------------------------------------------------------------------------//
//   FUNCTIONS                                                               //
//---------------------------------------------------------------------------//

void	Fixed::setRawBits(int const raw)	{ _rawNum = raw; }
int		Fixed::getRawBits(void) const		{ return (_rawNum); }
float	Fixed::toFloat(void) const			{ return (_rawNum + 0.0f) / (1 << _fractionalBit); }
int		Fixed::toInt(void) const			{ return _rawNum >> _fractionalBit; }

std::ostream&	operator << (std::ostream &num, const Fixed& other)
{
	num << other.toFloat();
	return num;
}
