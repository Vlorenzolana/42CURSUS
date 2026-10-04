/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:22:55 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/10/04 18:34:40 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp" // Incluye la clase Span y sus dependencias.
#include <ranges>

int main() // Punto de entrada del programa.
{
	Span basic(5); // Crea un Span con capacidad para cinco enteros.
	basic.addNumber(6); // Añade el primer valor mediante el método público de Span.
	basic.addNumber(3); // Añade un valor menor que el anterior.
	basic.addNumber(17); // Añade un valor mayor que los anteriores.
	basic.addNumber(9); // Añade otro valor intermedio.
	basic.addNumber(11); // Completa la capacidad del Span.
-

	try // Intenta superar la capacidad para comprobar la excepción de addNumber.
	{
		basic.addNumber(42); // Este sexto valor no puede entrar porque N vale cinco.
		std::cout << "Capacity test failed" << std::endl; // Solo se ejecutaría si faltara la comprobación.
	}
	catch (const std::exception& e) // Captura la excepción lanzada por Span.
	{
		std::cout << "Capacity test passed: " << e.what() << std::endl; // Confirma que el exceso se rechazó.
	}

	Span empty(0); // Crea un Span vacío con capacidad cero.
	try // Comprueba que no se puede calcular una distancia sin números.
	{
		empty.shortestSpan(); // Esta llamada debe lanzar una excepción.
		std::cout << "Empty test failed" << std::endl; // Solo se ejecutaría si faltara la comprobación.
	}
	catch (const std::exception& e) // Captura el error esperado.
	{
		std::cout << "Empty test passed: " << e.what() << std::endl; // Confirma el comportamiento correcto.
	}

	Span single(1); // Crea un Span que solo puede guardar un entero.
	single.addNumber(42); // Añade el único valor permitido.
	try // Comprueba que un único valor tampoco forma un intervalo.
	{
		single.longestSpan(); // Esta llamada debe lanzar una excepción.
		std::cout << "Single-value test failed" << std::endl; // Solo se ejecutaría si faltara la comprobación.
	}
	catch (const std::exception& e) // Captura el error esperado.
	{
		std::cout << "Single-value test passed: " << e.what() << std::endl; // Confirma que hace falta un par.
	}

	std::vector<int> values; // Crea los datos que se insertarán mediante un rango de iteradores.
	for (int i = 0; i < 10000; ++i) // Genera exactamente 10.000 números consecutivos.
		values.push_back(i); // Añade cada número al vector fuente.

	Span large(10000); // Reserva una capacidad exacta para los 10.000 valores.
	large.addRange(values.begin(), values.end()); // Copia el rango completo usando la plantilla addRange.
	std::cout << "Large shortest: " << large.shortestSpan() << std::endl; // Espera 1 entre números consecutivos.
	std::cout << "Large longest: " << large.longestSpan() << std::endl; // Espera 9999 entre 0 y 9999.

	Span rangeLimit(3); // Crea un Span pequeño para probar el límite de addRange.
	std::vector<int> tooMany; // Crea un rango que tendrá más elementos de los permitidos.
	tooMany.push_back(1); // Añade el primer elemento del rango demasiado grande.
	tooMany.push_back(2); // Añade el segundo elemento del rango demasiado grande.
	tooMany.push_back(3); // Añade el tercer elemento del rango demasiado grande.
	tooMany.push_back(4); // Añade el cuarto elemento, que hará que el rango no quepa.
	try // Comprueba que addRange rechaza el rango completo antes de insertar.
	{
		rangeLimit.addRange(tooMany.begin(), tooMany.end()); // Intenta insertar cuatro valores en capacidad tres.
		std::cout << "Range capacity test failed" << std::endl; // Solo se ejecutaría si faltara la comprobación.
	}
	catch (const std::exception& e) // Captura la excepción de capacidad.
	{
		std::cout << "Range capacity test passed: " << e.what() << std::endl; // Confirma que el rango fue rechazado.
	}

	return 0; // Indica al sistema operativo que todas las pruebas terminaron correctamente.
}