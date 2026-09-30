/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:51:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/10 11:59:56 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Shapeshifter")
{
	std::cout << "Animal " << type << " spawned!" << std::endl;
}
Animal::Animal(std::string newName): type(newName)
{
	std::cout << "Animal " << type << " spawned!" << std::endl;
}
Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal " << type << " spawned!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << type << " has been removed!" << std::endl;
}

Animal&	Animal::operator = (const Animal& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << type <<  ": Muuuuuuuuuu!" << std::endl;
}

const std::string&	Animal::getType() const
{
	return (type);
}
