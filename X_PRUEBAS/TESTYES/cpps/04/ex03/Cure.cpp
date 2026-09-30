/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:06:38 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/31 15:25:54 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():AMateria("cure"){}

Cure::Cure(const Cure& other):AMateria(other.type){}

Cure::~Cure(){}

Cure&	Cure::operator = (const Cure& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Cure*	Cure::clone() const {return (new Cure(*this));}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
