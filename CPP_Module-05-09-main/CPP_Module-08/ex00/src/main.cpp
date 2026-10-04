/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:01:15 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/10/04 17:50:21 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp" // Incluye la función plantilla easyfind y las cabeceras necesarias.

static void test_easyfind(std::vector<int>& vec, int value)
{
    try
    {
        std::vector<int>::iterator it = easyfind(vec, value);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Value " << value << " not found" << std::endl;
    }
}

int main() // Punto de entrada del programa.
{
	std::vector<int> vec; // Crea un vector vacío de enteros.
	vec.push_back(1); // Añade el primer valor al final del vector.
	vec.push_back(2); // Añade el segundo valor al final del vector.
	vec.push_back(3); // Añade el tercer valor, que será encontrado.
	vec.push_back(4); // Añade el cuarto valor al vector.
	vec.push_back(5); // Añade el quinto valor al vector.

	test_easyfind(vec, 3);
	test_easyfind(vec, 6);
	
	return 0; // Indica que el programa terminó correctamente.
}
