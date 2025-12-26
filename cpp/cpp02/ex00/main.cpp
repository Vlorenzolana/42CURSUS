/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:25:19 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 17:25:22 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int	main(void)
{
	Fixed	a;										//	Instanciamos 'a' con el constructor por defecto.
	Fixed	b(a);									//	Instanciamos 'b' como una copia de 'a'.
	Fixed	c;										//	Instanciamos 'c' con el constructor por defecto.
	
	c = b;											//	Asignamos a 'c' los valores de 'b'.

	std::cout << a.getRawBits() << std::endl;		//	Leemos el dato con su método getter.
	std::cout << b.getRawBits() << std::endl;		//	Ídem.
	std::cout << c.getRawBits() << std::endl;		//	Ídem.

	return (0);
}