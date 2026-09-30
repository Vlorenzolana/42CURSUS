/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:06:38 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/31 15:25:57 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():AMateria("ice"){}

Ice::Ice(const Ice& other):AMateria(other.type){}

Ice::~Ice(){}

Ice&	Ice::operator = (const Ice& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Ice*	Ice::clone() const {return (new Ice(*this));}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
