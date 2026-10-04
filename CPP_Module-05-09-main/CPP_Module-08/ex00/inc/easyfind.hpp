/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:03:22 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/09/29 18:49:05 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP // Evita incluir esta cabecera más de una vez en la misma unidad de compilación.
# define EASYFIND_HPP // Activa la protección definida por EASYFIND_HPP.

#include <algorithm> // Proporciona std::find, el algoritmo genérico de búsqueda.
#include <stdexcept> // Proporciona std::runtime_error para informar de valores ausentes.
#include <iostream> // Proporciona herramientas de entrada y salida usadas por los tests.
#include <vector> // Proporciona std::vector, el contenedor usado en main.cpp.

template <typename T> // Declara una plantilla: T será el tipo del contenedor recibido.

typename T::iterator easyfind(T& container, int value) // Devuelve un iterador al primer int encontrado.
{
    typename T::iterator it = std::find(container.begin(), container.end(), value); // Busca desde begin hasta end.
    if(it == container.end()) // end representa la posición posterior al último elemento, no un elemento válido.
        throw std::runtime_error("Value not found"); // Informa mediante una excepción de que no hubo coincidencia.
    return it; // Devuelve el iterador que apunta a la primera coincidencia.
}

#endif // Fin de la protección contra inclusiones repetidas.