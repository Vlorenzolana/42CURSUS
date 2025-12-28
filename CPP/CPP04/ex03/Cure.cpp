/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:26:53 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:26:56 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
# include "ICharacter.hpp"

Cure::Cure()
{
	std::cout << "-> Cure default constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure& original)
{
	std::cout << "-> Cure copy constructor called" << std::endl;
	_type = original._type;
}

Cure::~Cure()
{
	std::cout << "-> Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure* Cure::clone() const
{
	std::cout << "-> Cure cloning method called" << std::endl;
	Cure* paste = new Cure();
	return paste;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
}