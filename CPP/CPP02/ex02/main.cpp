/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:25:54 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/07 19:46:28 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int	main(void)
{
	Fixed	a;

	Fixed	const b(Fixed(5.5f) * Fixed(2));
	std::cout << std::endl << "Input values:" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << std::endl << "Testing arithmetic operators:" << std::endl;
	std::cout << "Addition:       " << a + b << std::endl;
	std::cout << "Substraction:   " << a - b << std::endl;
	std::cout << "Multiplication: " << a * b << std::endl;
	std::cout << "Division:       " << a / b << std::endl;
	std::cout << std::endl << "Testing comparison operators:" << std::endl;
	if (a == b)
		std::cout << "a and b are equal" << std::endl;
	if (a != b)
		std::cout << "a and b are different" << std::endl;
	if (a < b)
		std::cout << "a is strictly smaller than b" << std::endl;
	if (a > b)
		std::cout << "a is strictly greater than b" << std::endl;
	if (a <= b)
		std::cout << "a is smaller than or equal to b" << std::endl;
	if (a >= b)
		std::cout << "a is greater than or equal to b" << std::endl;
	std::cout << std::endl;
	std::cout << "Current a:                                    " << a << std::endl;
	std::cout << "Pre-increment a,
		then show it:                " << ++a << std::endl;
	std::cout << "Show a and Post-increment it:                 " << a++ << std::endl;
	std::cout << "Show a againt to prove it was incremented:    " << a << std::endl;
	std::cout << "Show b:                                       " << b << std::endl;
	std::cout << "Find min between a and b:                     " << Fixed::min( a,
		b ) << std::endl;
	std::cout << "Find max between a and b:                     " << Fixed::max( a,
		b ) << std::endl;
	return (0);
}
 */

int	main(void)
{
	Fixed a(999999999.0f);
	Fixed const b(999999999.0f);
	
	//(>, <, >=, <=, == and !=)
	(a > b) ? std::cout << "a is not less than b" << std::endl : std::cout << "a is less or the same as b" << std::endl;

	(a < b) ? std::cout << "a is less or the same than b" << std::endl : std::cout << "a not less than b" << std::endl;

	(a >= b) ? std::cout << "a is less or the same than b" << std::endl : std::cout << "b is less than a" << std::endl;

	(a <= b) ? std::cout << "a is less or the same than b" << std::endl : std::cout << "b is less than a" << std::endl;

	(a == b) ? std::cout << "a is same than b" << std::endl : std::cout << "b is less than a" << std::endl;

	(a != b) ? std::cout << "a is less than b" << std::endl : std::cout << "b is less than a" << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	if (b != 0)
		std::cout << "a / b = " << a / b << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;

	Fixed c;
	Fixed const d(Fixed(5.06f) * Fixed(0));
	std::cout << "Subject tests:" << std::endl;
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	return (0);
}
