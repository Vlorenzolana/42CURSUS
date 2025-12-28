/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:20:02 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:20:09 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	_type = "wrong amorfous blob";
}

WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	_type = original._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

void	WrongAnimal::makeSound()
{
	std::cout << "The " << _type << " goes wrong bleeeeeeuaaaarrrrghhhhh!" << std::endl;
}
