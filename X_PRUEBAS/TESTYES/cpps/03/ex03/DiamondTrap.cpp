/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:05:16 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/07 12:26:08 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("DEFAULT_clap_name"), name("DEFAULT")
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;

	std::cout << "DiamondTrap " << this->name << " spawned!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string newName): ClapTrap(newName + "_clap_name"), name(newName)
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;

	std::cout << "DiamondTrap " << this->name << " spawned!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other.ClapTrap::name + "_clap_name")
{
	*this = other;

	std::cout << "DiamondTrap COPY " << this->name << " spawned!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " has been removed!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		hitPoints = other.hitPoints;
		attackDamage = other.attackDamage;
		energyPoints = other.energyPoints;
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm DiamondTrap " << this->name << ", and my ClapTrap's name is " << ClapTrap::name << "." << std::endl;
}
