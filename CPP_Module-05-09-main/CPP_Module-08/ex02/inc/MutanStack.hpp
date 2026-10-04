/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:55:23 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/10/01 18:55:30 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP // Evita incluir esta cabecera varias veces.
#define MUTANTSTACK_HPP // Activa la protección contra inclusiones repetidas.

#include <stack> // Proporciona std::stack, el adaptador de contenedor que vamos a extender.
#include <iostream> // Proporciona herramientas de entrada y salida disponibles para los ejemplos.

template <typename T> // T representa el tipo de elemento almacenado en la pila.
class MutantStack : public std::stack<T> // Hereda la interfaz de std::stack y añade iteradores.
{
	public:
		MutantStack() : std::stack<T>() {} // Construye una pila vacía usando el constructor de la clase base.
		MutantStack(const MutantStack& other) : std::stack<T>(other) {} // Copia la pila mediante el constructor base.
		~MutantStack() {} // Destruye la pila; la clase base libera su contenedor automáticamente.

		MutantStack& operator=(const MutantStack& other) // Asigna el contenido de otra MutantStack.
		{
			if (this != &other) // Evita asignar el objeto sobre sí mismo.
				std::stack<T>::operator=(other); // Delega la copia del contenedor en la clase base.
			return *this; // Permite encadenar asignaciones.
		}

		typedef typename std::stack<T>::container_type::iterator iterator; // Alias para el iterador del contenedor interno.
		iterator begin() // Devuelve un iterador al primer elemento del contenedor interno.
		{
			return this -> c.begin(); // c es el miembro protegido que std::stack usa para guardar los elementos.
		}
		
		iterator end() // Devuelve el iterador situado después del último elemento.
		{
			return this -> c.end(); // Ese valor marca el final y no debe desreferenciarse.
		}

		void	push(const T& value) // Añade un elemento en la parte superior de la pila.
		{
			std::stack<T>::push(value); // Reutiliza la implementación estándar de push.
		}

		void	pop() // Elimina el elemento situado en la parte superior.
		{
			std::stack<T>::pop(); // Reutiliza la implementación estándar de pop.
		}

		T& top() // Devuelve una referencia modificable al elemento superior.
		{
			return std::stack<T>::top(); // Delega la búsqueda del elemento superior en std::stack.
		}

		const T& top() const // Versión para objetos const que devuelve una referencia de solo lectura.
		{
			return std::stack<T>::top(); // Conserva la const-correctness de la clase base.
		}

		size_t size() const // Devuelve cuántos elementos contiene la pila.
		{
			return std::stack<T>::size(); // Delega el cálculo del tamaño en std::stack.
		}
};

#endif // Fin de la protección contra inclusiones repetidas.