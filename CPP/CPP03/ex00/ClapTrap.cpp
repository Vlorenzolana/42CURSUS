/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:23:44 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/11 00:23:48 by vlorenzo         ###   ########.fr       */
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
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_dmg = other._attack_dmg;
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
	if (amount > 1000)
	{
		std::cout << "ClapTrap " << _name << " cannot take invalid damage amount!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
	if (amount >= static_cast<unsigned int>(_hit_points))
		_hit_points = 0;
	else
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
		if (amount > 1000)
		{
			std::cout << "ClapTrap " << _name << " cannot repair with invalid amount!" << std::endl;
			return ;
		}
		std::cout << "ClapTrap " << _name << " repairs itself and gains " << amount << " hit points" << std::endl;
		_energy_points--;
		if (static_cast<unsigned int>(_hit_points) + amount > 1000)
			_hit_points = 1000;
		else
			_hit_points += amount;
	}
}
