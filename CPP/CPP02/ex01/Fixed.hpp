/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:25:31 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/30 19:23:10 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:

		int					_value;
		static const int	_fbits = 8;
		
	public:
	
		Fixed();
		Fixed(const Fixed& model);
		Fixed(const int number);				//	Constructor custom que toma un int como parámetro.
		Fixed(const float number);				//	Constructor custom que toma un float como parámetro.
		~Fixed();

		Fixed&	operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;			//	Converts fixed-point value to float.
		int		toInt( void ) const;			//	Converts fixed-point value to int.
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_obj);		//	Declare overload outside class because left-hand operand of "<<" (usually std::cout) is not a member of Fixed.
