/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:43:54 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/10/01 18:40:12 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN2_HPP // Evita incluir este archivo de cabecera más de una vez.
#define SPAN2_HPP // Define la macro que activa la protección contra inclusiones repetidas.

#include <vector> // Proporciona std::vector, el contenedor donde se guardan los números.
#include <stdexcept> // Proporciona std::runtime_error para informar de errores de ejecución.
#include <limits> // Proporciona el valor máximo posible para long long.
#include <algorithm> // Proporciona algoritmos como std::distance, std::min_element y std::max_element.
#include <iostream> // Proporciona herramientas de entrada y salida incluidas por el ejercicio.

class Span // Representa una colección con una capacidad máxima y operaciones sobre sus distancias.
{
	private:
		unsigned int _N; // Guarda cuántos números como máximo puede contener el objeto.
		std::vector<int> _numbers; // Guarda los números añadidos hasta el momento.

	public:
		Span(unsigned int N); // Constructor que recibe la capacidad máxima.
		Span(const Span& other); // Constructor de copia que duplica otro Span.
		Span& operator=(const Span& other); // Operador de asignación que copia otro Span.
		~Span(); // Destructor llamado cuando el objeto deja de existir.
		void addNumber(int number); // Añade un número si todavía queda espacio.
		long long shortestSpan() const; // Devuelve la distancia más pequeña entre dos números.
		long long longestSpan() const; // Devuelve la distancia más grande entre dos números.

		template <typename T> // T permite aceptar distintos tipos de iteradores.
		
		void addRange(T begin, T end) // Añade todos los elementos del intervalo [begin, end).
		{
			if(_numbers.size() + std::distance(begin, end) > _N) // Comprueba la capacidad antes de modificar el vector.
				throw std::runtime_error("Not enough space"); // Lanza una excepción si el intervalo no cabe completo.
			for (T it = begin; it != end; ++it) // Recorre el intervalo usando un iterador.
				_numbers.push_back(*it); // Desreferencia el iterador y copia el valor al vector.
		}
};

#endif // Fin de la protección contra inclusiones repetidas.