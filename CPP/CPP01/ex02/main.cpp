/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:47:01 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:47:04 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPtr = &string;
	std::string	&stringRef = string;

	std::cout << "Memory address of string variable:       " << &string << std::endl;		//	Address of var
	std::cout << "Memory address held by stringPtr:        " << &stringPtr << std::endl;	//	Address of pointer
	std::cout << "Memory address pointed to by stringPtr:  " << stringPtr << std::endl;		//	Pointed to by pointer
	std::cout << "Memory address held by stringRef:        " << &stringRef << std::endl;	//	Same address as var: Reference in an alias for the actual var.
	std::cout << std::endl;
	std::cout << "Value of string variable:                " << string << std::endl;		//	Message
	std::cout << "Value pointed to by stringPtr:           " << *stringPtr << std::endl;	//	Dereference to message
	std::cout << "Value pointed to by stringRef:           " << stringRef << std::endl;		//	Message

	return (0);
}
