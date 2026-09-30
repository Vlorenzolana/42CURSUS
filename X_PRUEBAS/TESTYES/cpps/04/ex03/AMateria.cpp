/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 03:25:54 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/24 13:22:02 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {type = "Materia";}

AMateria::AMateria(std::string const & newType) {type = newType;}

AMateria::AMateria(const AMateria* other) {*this = other;}

AMateria::~AMateria(){}

AMateria& AMateria::operator = (const AMateria* other)
{
	if (this != other)
		this->type = other->type;
	return (*this);
}

const std::string& AMateria::getType() const {return this->type;}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "* Random bullshit go !" << std::endl;
}
