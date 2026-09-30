/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:24:55 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/06 18:36:16 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_rawNum;
		static const int	_fractionalBit = 8;
	
	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed& copy);
		Fixed& operator = (const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif