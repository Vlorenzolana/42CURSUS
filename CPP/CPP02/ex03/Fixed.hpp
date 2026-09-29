/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:42:15 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 13:42:17 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:

		int					_value;
		static const int	_fbits = 8;

	public:
	
		Fixed();
		Fixed(const Fixed& model);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();

		Fixed&	operator=(const Fixed& other);

		bool	operator>(const Fixed& other) const;		//	By implementing these overloads, we can apply comparison operators
		bool	operator<(const Fixed& other) const;		//	directly on objects of the Fixed class. 
		bool	operator>=(const Fixed& other) const;		//	Return is bool type. Neither object will change.
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;		//	By implementing these overloads, we can apply arithmetic operators
		Fixed	operator-(const Fixed& other) const;		//	directly on objects of the Fixed class. 
		Fixed	operator*(const Fixed& other) const;		//	Return is Fixed type. Neither object will change; a new object will be returned instead.
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++();								// Pre-increment. Increments the object's value and then returns a reference to the modified object.
		Fixed	operator++(int);							// Post-increment. Returns a copy of the object's value before incrementing, and then increments the object's value.
		Fixed&	operator--();								// Pre-decrement.
		Fixed	operator--(int);							// Post-decrement.

		static Fixed& min(Fixed& one, Fixed& another);						//	Bad things might happen here...
		static const Fixed& min(const Fixed& one, const Fixed& another);	//	This is better and stronger and correct. No badness here.
		static Fixed& max(Fixed& one, Fixed& another);
		static const Fixed& max(const Fixed& one, const Fixed& another);


		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_obj);