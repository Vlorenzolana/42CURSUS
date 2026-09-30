/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:55:18 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/10 12:09:48 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Suspicious WrongCat"), type("WrongCat")
{
	std::cout << this->type << " spawned!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal("Suspicious " + other.type), type(other.type)
{
	std::cout << this->type << " spawned!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->type << " has been removed!" << std::endl;
}

WrongCat&	WrongCat::operator = (const WrongCat& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << this->type <<  ": MOOOOOOOW!" << std::endl;
}
