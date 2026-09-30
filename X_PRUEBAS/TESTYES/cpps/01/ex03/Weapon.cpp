/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:30:09 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/10 12:13:09 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
	type = newType;
}

Weapon::~Weapon(){}

const std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}