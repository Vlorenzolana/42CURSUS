/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:22:42 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:53:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string callsign) : ClapTrap(callsign + "_clap_name"),  ScavTrap(callsign), FragTrap(callsign)
{
	std::cout << "Custom DiamondTrap " << callsign << " constructor called" << std::endl;
	_name = callsign;
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_dmg = FragTrap::_attack_dmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap& model) : ScavTrap(model), FragTrap(model)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name = model._name;
	_hit_points = model._hit_points;
	_energy_points = model._energy_points;
	_attack_dmg = model._attack_dmg;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_hit_points = other._hit_points;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << " and I also am " << ClapTrap::_name << std::endl;
}
