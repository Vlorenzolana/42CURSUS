/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:04:52 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/10/04 18:13:03 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp" // Incluye la declaración de la clase Span.

Span::Span(unsigned int N) : _N(N), _numbers() {} // inicializa la capacidad y crea un contenedor vacio de integers

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {} // Copia la capacidad y todos los números.


Span& Span::operator=(const Span& other) // Copia el contenido de otro objeto ya construido.
{
	if(this != &other) // Evita copiar el objeto sobre sí mismo.
	{
		_N = other._N; // Copia la capacidad máxima.
		_numbers = other._numbers; // Copia el vector; std::vector gestiona su propia memoria.
	}
	return *this; // Devuelve el objeto actual para permitir expresiones como a = b = c.
}

Span::~Span() // El vector libera automáticamente su memoria al destruirse.
{
}

void Span::addNumber(int number) // Añade un único número al Span.
{
	if(_numbers.size() >= _N) // size() indica cuántos elementos hay actualmente.
		throw std::runtime_error("Not enough numbers"); // Impide superar la capacidad definida por _N.
	_numbers.push_back(number); // Inserta el número al final del vector.
}

long long Span::shortestSpan() const // Calcula la menor distancia entre dos números.
{
	if (_numbers.size() < 2) // Hace falta un par de números para calcular una distancia.
		throw std::runtime_error("Not enough numbers"); // Informa al llamador de que faltan datos.

	std::vector<int> sortedNumbers = _numbers; // Trabaja sobre una copia para no modificar el orden original.
	std::sort(sortedNumbers.begin(), sortedNumbers.end()); // Ordena de menor a mayor para comparar vecinos.

	long long minSpan = std::numeric_limits<long long>::max(); // Valor inicial grande para poder encontrar un mínimo.

	for (size_t i = 1; i < sortedNumbers.size(); i++) // Comienza en el segundo elemento para mirar cada pareja vecina.
	{
		long long span = static_cast<long long>(sortedNumbers[i]) - // Convierte antes de restar para trabajar con long long.
							static_cast<long long>(sortedNumbers[i - 1]); // La diferencia entre vecinos es una distancia candidata.
		if (span < minSpan) // Comprueba si la distancia actual es la más pequeña encontrada.
			minSpan = span; // Guarda la nueva distancia mínima.
	}
	return minSpan; // Devuelve la menor distancia calculada.
}

long long Span::longestSpan() const // Calcula la mayor distancia posible entre dos números.
{
	if (_numbers.size() < 2) // También hacen falta al menos dos números para esta operación.
		throw std::runtime_error("Not enough numbers"); // Lanza un error si no hay suficientes datos.
		
	long long min = *std::min_element(_numbers.begin(), _numbers.end()); // Obtiene el menor elemento y lo desreferencia.
	long long max = *std::max_element(_numbers.begin(), _numbers.end()); // Obtiene el mayor elemento y lo desreferencia.

	return max - min; // La distancia máxima siempre es mayor menos menor.
}