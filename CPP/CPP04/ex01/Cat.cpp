/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:22:03 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:22:05 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_cerebellum = new Brain();
}

Cat::Cat(const Cat& original)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = original._type;
	//_cerebellum = original._cerebellum;				//	This line will perform a shallow copy. Only the address of the pointer will be copied.
	_cerebellum = new Brain(*original._cerebellum);		//	This is it. Instantiate a new Brain and use the Copy constructor.
}

Cat::~Cat()
{
	delete _cerebellum;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _cerebellum;
		_cerebellum = new Brain(*(other._cerebellum));
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "The " << this->getType() << " goes meow meow!" << std::endl;
}

const Brain* Cat::getBrain() const
{
    return _cerebellum;
}