/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:24:40 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/11 00:24:09 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string callsign) : ClapTrap(callsign)
{
	std::cout << "Custom ScavTrap " << callsign << " constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_name = original._name;
	_hit_points = original._hit_points;
	_energy_points = original._energy_points;
	_attack_dmg = original._attack_dmg;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is guarding the gate" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_dmg = other._attack_dmg;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hit_points < 1)
		return ;
	if (_energy_points < 1)
		std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attack_dmg << " points of damage!" << std::endl;
		_energy_points--;
	}
}
