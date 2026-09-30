/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:55:18 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/16 19:21:58 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Suspicious Cat"), type("Cat")
{
	std::cout << this->type << " spawned!" << std::endl;
}

Cat::Cat(const Cat& other): Animal("Suspicious " + other.type), type(other.type)
{
	std::cout << this->type << " spawned!" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->type << " has been removed!" << std::endl;
}

Cat&	Cat::operator = (const Cat& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << this->type <<  ": Meow!" << std::endl;
}
