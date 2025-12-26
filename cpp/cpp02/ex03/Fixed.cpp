/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:36:30 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:40:26 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed& model)
{
	//std::cout << "Copy constructor called" << std::endl;
	_value = model._value;
}

Fixed::Fixed(const int number)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = number << _fbits;
}

Fixed::Fixed(const float number)
{
	//std::cout << "Float constructor called" << std::endl;
	float scale_factor = (1 << _fbits);
	_value = static_cast<int>(roundf(number * scale_factor));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
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
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_value = other._value;
	return (*this);
}

bool	Fixed::operator>(const Fixed& other) const			//	Compare the raw integer _value of the two Fixed objects.
{															//	Since both fixed-point numbers have the same scaling (same _fbits),
	return (this->_value > other._value);					//	a direct comparison of their underlying integer values is accurate.
}

bool	Fixed::operator<(const Fixed& other) const			//	...
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const			//	...
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const			//	...
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const			//	...
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const			//	Compare the raw integer _value of the two Fixed objects.
{															//	Since both fixed-point numbers have the same scaling (same _fbits),
	return (this->_value != other._value);					//	a direct comparison of their underlying integer values is accurate.
}

Fixed	Fixed::operator+(const Fixed& other) const			//	Operate two objects of the Fixed class.
{
	Fixed result;											//	Return a new object as result.
	
	result._value = this->_value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const			//	...
{
	Fixed result;
	
	result._value = this->_value - other._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const			//	...
{
	Fixed result;
	
	result._value = (static_cast<long long>(this->_value) * other._value) / (1 << _fbits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const			//	Operate two objects of the Fixed class.
{
	if (other._value == 0)
	{
		std::cout << "Cannot divide by ";
		return (Fixed(0));
	}
	Fixed result;											//	Return a new object as result.
	
	result._value = (this->_value  * (1 << _fbits)) / other._value;
	return (result);
}

Fixed&	Fixed::operator++()		//	Increments the object's value and then returns a reference to the modified object.
{
	this->_value++;				//	Increment object value.
	return (*this);				//	Return object.
}

Fixed	Fixed::operator++(int)		//	Returns a copy of the object's value before incrementing, and then increments the object's value.
{
	Fixed aux = *this;			//	Create a copy of the object's current state
	this->_value++;				//	Increment the original object value.
	return (aux);				//	Return the not-incremented copy.
}

Fixed&	Fixed::operator--()
{
	this->_value--;				//	Decrement object value.
	return (*this);				//	Return object.
}

Fixed	Fixed::operator--(int)
{
	Fixed aux = *this;			//	Create a copy of the object's current state
	this->_value--;				//	Decrement the original object value.
	return (aux);				//	Return the not-decremented copy.
}

Fixed& Fixed::min(Fixed& one, Fixed& another)						//	This is BAD PRACTICE
{
	if (one < another)
		return (one);
	else
		return (another);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& another)		// This is GOOD PRACTICE
{
	if (one < another)
		return (one);
	else
		return (another);
}

Fixed& Fixed::max(Fixed& one, Fixed& another)						//	BAD. Weak, could change values.
{
	if (one > another)
		return (one);
	else
		return (another);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& another)		// GOOD. Strong. Unchangeable values.
{
	if (one > another)
		return (one);
	else
		return (another);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits getter function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits setter function called" << std::endl;
	_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_obj)
{
	os << fixed_obj.toFloat();			//	Convert the fixed_obj to its float representation using the toFloat() method, then insert it into the output stream.
	return (os); 						//	Return the stream to allow chaining
}
