/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:20:40 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:20:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& original)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = original._type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "The " << this->getType() << " goes woof woof!" << std::endl;
}