/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:55:18 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/07 12:45:12 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " spawned!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " spawned!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap COPY " << name << " spawned!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been REMOVED!" << std::endl;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap& other)
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

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
		std::cout << "ScavTrap " << name << " is DEAD!" << std::endl;
	else if (energyPoints <= 0)
		std::cout << "ScavTrap " << name << " has no ENERGY left!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << name << " ATTACKS " << target << " causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints --;
	}	
}
		
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is in GATE KEEPER mode!" << std::endl;
}
