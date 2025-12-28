/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:21:11 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:21:13 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& original)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = original._type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "The " << this->getType() << std::endl;
}