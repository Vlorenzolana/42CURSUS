/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:55:18 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/16 19:21:58 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Suspicious Dog")
{
	this->type = "Dog";
	brain = new Brain("Foooooooood");
	std::cout << this->type << " spawned!" << std::endl;
}

Dog::Dog(const Dog& other): Animal("Suspicious " + other.type)
{
	brain = new Brain(*other.brain);
	std::cout << this->type << " spawned!" << std::endl;
}

Dog::~Dog()
{
	delete	brain;
	std::cout << this->type << " has been removed!" << std::endl;
}

Dog&	Dog::operator = (const Dog& other)
{
	if (this != &other)
	{
		this->Animal::type = other.Animal::type;
		this->type = other.type;
		this->brain = other.brain;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << this->type <<  ": Guau!" << std::endl;
}
