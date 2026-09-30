/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:24:55 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/06 12:39:38 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_rawNum;
		static const int	_fractionalBit = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const float num);
		Fixed(const int num);
		~Fixed();
		
		//COMPARISONS
		bool	operator >  (const Fixed& other);
		bool	operator <  (const Fixed& other);
		bool	operator >= (const Fixed& other);
		bool	operator <= (const Fixed& other);
		bool	operator == (const Fixed& other);
		bool	operator != (const Fixed& other);
		
		//ARITHMETICS
		Fixed&	operator = (const Fixed& other);
		Fixed	operator + (const Fixed& other);
		Fixed	operator - (const Fixed& other);
		Fixed	operator * (const Fixed& other);
		Fixed	operator / (const Fixed& other);

		//INCREMENT // DECREMENT
		Fixed	operator ++ ();		//Pre-increment
		Fixed	operator -- ();		//Pre-increment
		Fixed	operator ++ (int);	//Post-increment
		Fixed	operator -- (int);	//Post-increment

		//MIN // MAX
		static Fixed&		min(Fixed& one, Fixed& two);
		static const Fixed&	min(const Fixed& one, const Fixed& two);
		static Fixed&		max(Fixed& one, Fixed& two);
		static const Fixed&	max(const Fixed& one, const Fixed& two);

		//FUNCTIONS
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator << (std::ostream &num, const Fixed& other);

#endif