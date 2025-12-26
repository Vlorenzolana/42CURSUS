/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:25:36 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 17:25:38 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int	main(void)
{
	Fixed		a;									//	Instanciamos 'a' con el constructor por defecto.
	Fixed const	b(10);								//	Instanciamos 'b' con el constructor de int.
	Fixed const	c(42.42f);							//	Instanciamos 'c' con el constructor de float.
	Fixed const	d(b);								//	Instanciamos 'd' con el constructor de copia.

	a = Fixed(1234.4321f);							//	Asignamos a 'a' la copia del objeto creado con ese valor float.

	std::cout << std::endl;
	std::cout << "a is " << a << std::endl;			//	Podemos imprimir objetos directamente gracias al "insertion operator overload".
	std::cout << "b is " << b << std::endl;			//	No necesitamos el getter.
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	return (0);
}
