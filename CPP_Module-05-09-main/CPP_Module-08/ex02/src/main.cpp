/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:50:23 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/10/01 18:53:33 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp" // Incluye la pila personalizada y sus métodos.

int main() // Punto de entrada del programa.
{
	MutantStack<int> mstack; // Crea una pila de enteros que también permite iterar.
	mstack.push(5); // Inserta 5 en la parte superior.
	mstack.push(17); // Inserta 17 encima de 5.
	std::cout << mstack.top() << std::endl; // Muestra el elemento superior, que es 17.
	mstack.pop(); // Elimina el elemento superior, 17.
	std::cout << mstack.size() << std::endl; // Muestra que queda un elemento en la pila.
	mstack.push(3); // Añade 3 a la pila.
	mstack.push(5); // Añade otro 5.
	mstack.push(737); // Añade 737.
	mstack.push(0); // Añade 0 como nuevo elemento superior.
	MutantStack<int>::iterator it = mstack.begin(); // Obtiene un iterador al primer elemento interno.
	MutantStack<int>::iterator ite = mstack.end(); // Obtiene el marcador posterior al último elemento.
	++it; // Avanza una posición para demostrar que el iterador puede incrementarse.
	--it; // Retrocede a la posición inicial para recorrer todos los elementos.
	while (it != ite) // Continúa mientras el iterador no haya llegado al final.
	{
		std::cout << *it << std::endl; // Desreferencia el iterador y muestra el valor actual.
		++it; // Avanza al siguiente elemento.
	}
	std::stack<int> s(mstack); // Construye una std::stack copiando la pila personalizada.
	return 0; // Indica que el programa terminó correctamente.
}

/* int main()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	//std::stack<int> s(mstack);
	return 0;
}
 */
