/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:56:59 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/06 12:13:04 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "The biggest: " << Fixed::max( a, b ) << std::endl;

	if (a > b)
		std::cout << a << " is bigger than " << b << std::endl;
	if (a < b)
		std::cout << b << " is bigger than " << a << std::endl;
	if (a != b)
		std::cout << "not the same :/" << std::endl;
	
	std::cout << "The sum: " << a + b << std::endl;
	std::cout << "Division (11.5 / 2): " << Fixed(11.5f) / Fixed(2) << std::endl;
	std::cout << "Multiplikation (11.5 * 2): " << Fixed(11.5f) * Fixed(2) << std::endl;
	
	return 0;
}
