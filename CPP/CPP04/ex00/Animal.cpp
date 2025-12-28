/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:21:01 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:21:04 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	_type = "amorfous blob";
}

Animal::Animal(const Animal& original)
{
	std::cout << "Animal copy constructor called" << std::endl;
	_type = original._type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "The " << this->getType() << " goes bleeeeeeeuuuuaaaaaaarrrgghhhh!" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}