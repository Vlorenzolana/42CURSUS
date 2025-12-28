/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:06:29 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:45:28 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string callsign )
{
	std::cout << "Custom ClapTrap " << callsign << " constructor called" << std::endl;
	_name = callsign;
	_hit_points = 10;
	_energy_points = 10;
	_attack_dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = original._name;
    _hit_points = original._hit_points;
    _energy_points = original._energy_points;
    _attack_dmg = original._attack_dmg;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_hit_points = other._hit_points;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hit_points < 1)
		return ;
	if (_energy_points < 1)
		std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attack_dmg << " points of damage!" << std::endl;
		_energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
	_hit_points -= amount;
	if (_hit_points < 1)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points < 1)
		return ;
	if (_energy_points < 1)
		std::cout << "ClapTrap " << _name << " has no energy left to repair itself!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " repairs itself and gains " << amount << " hit points" << std::endl;
		_energy_points--;
		_hit_points += amount;
	}
}

void	ClapTrap::setHitPoints(int amount)
{
	_hit_points = amount;
}

void	ClapTrap::setEnergyPoints(int amount)
{
	_energy_points = amount;
}

void	ClapTrap::setAttackDamage(int amount)
{
	_attack_dmg = amount;
}