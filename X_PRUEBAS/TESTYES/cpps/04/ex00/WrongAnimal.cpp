/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:51:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/17 17:20:36 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Shapeshifter")
{
	std::cout << "WrongAnimal " << type << " spawned!" << std::endl;
}
WrongAnimal::WrongAnimal(std::string newName): type(newName)
{
	std::cout << "WrongAnimal " << type << " spawned!" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
	std::cout << "WrongAnimal " << type << " spawned!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << type << " has been removed!" << std::endl;
}

WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << type <<  ": Muuuuuuuuuu!" << std::endl;
}

const std::string&	WrongAnimal::getType() const
{
	return (type);
}
