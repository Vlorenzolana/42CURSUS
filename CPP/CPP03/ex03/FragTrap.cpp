/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:21:43 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:53:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string callsign) : ClapTrap(callsign)
{
	std::cout << "Custom FragTrap " << callsign << " constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_name = original._name;
	_hit_points = original._hit_points;
	_energy_points = original._energy_points;
	_attack_dmg = original._attack_dmg;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " high fives you! Yeah!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_hit_points = other._hit_points;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (_hit_points < 1)
		return ;
	if (_energy_points < 1)
		std::cout << "FragTrap " << _name << " has no energy left to attack!" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attack_dmg << " points of damage!" << std::endl;
		_energy_points--;
	}
}