/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:51:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/07 13:00:06 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("DEFAULT"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " spawned!" << std::endl;
}
ClapTrap::ClapTrap(std::string newName): name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " spawned!" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;

	std::cout << "ClapTrap COPY " << name << " spawned!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been REMOVED!" << std::endl;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		attackDamage = other.attackDamage;
		energyPoints = other.energyPoints;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
		std::cout << "ClapTrap " << name << " is DEAD!" << std::endl;
	else if (energyPoints <= 0)
		std::cout << "ClapTrap " << name << " has no ENERGY left!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " ATTACKS " << target << " causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints --;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
		std::cout << "ClapTrap " << name << " is DEAD!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " TAKES " << amount << " points of damage!" << std::endl;
		hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
		std::cout << "ClapTrap " << name << " is DEAD!" << std::endl;
	else if (energyPoints <= 0)
		std::cout << "ClapTrap " << name << " has no ENERGY left!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " REPAIRS " << amount << " points of damage!" << std::endl;
		hitPoints += amount ;
		energyPoints --;
	}
}
