/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:51:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/07 11:43:15 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("DEFAULT"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " spawned!" << std::endl;
}
ClapTrap::ClapTrap(std::string newName): _name(newName), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " spawned!" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;

	std::cout << "ClapTrap COPY " << _name << " spawned!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been REMOVED!" << std::endl;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_attackDamage = other._attackDamage;
		_energyPoints = other._energyPoints;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is DEAD!" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no ENERGY left!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " ATTACKS " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints --;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is DEAD!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " TAKES " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is DEAD!" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no ENERGY left!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " REPAIRS " << amount << " points of damage!" << std::endl;
		_hitPoints += amount;
		_energyPoints --;
	}
}
