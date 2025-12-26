/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:48:18 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:48:20 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string w_type)
{
	_type = w_type;
}

Weapon::~Weapon()
{
	std::cout << _type << " has been dropped" << std::endl;
}

std::string	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}