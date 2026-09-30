/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:55:18 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/07 12:50:35 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;

	std::cout << "FragTrap " << name << " spawned!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;

	std::cout << "FragTrap " << name << " spawned!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap COPY " << name << " spawned!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been REMOVED!" << std::endl;
}

FragTrap&	FragTrap::operator = (const FragTrap& other)
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " asks for a HIGH FIVE!" << std::endl;
}
