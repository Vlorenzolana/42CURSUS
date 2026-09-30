/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:28:10 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/05 11:14:47 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";

	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "Memory address:" << std::endl;
	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	
	std::cout << "\nValue:" << std::endl;
	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	
	return (0);
}

/*
-> Features:
	- What it is
	- Access to the value
	- Reassigning
	- Ease of use

-> Reference: (int&)
	- Alias for an existing variable
	- Use the name of the reference
	- You cannot change which variable it refers to
	- Simpler (looks like the same variable)

-> Pointer: (int*)
	- Stores the address of another variable
	- You need to use * (dereference)
	- You can change the address it points to
	- Requires more care (e.g., avoiding null pointers)
*/
