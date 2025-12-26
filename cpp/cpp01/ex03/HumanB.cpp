/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:47:51 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:47:53 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << "Spawned HumanB " << _name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << _name << " has fled the battle" << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their ";

	if (hitter != NULL)
		std::cout << hitter->getType();
	else
		std::cout << "bare hands (no weapon equipped)";
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon *bow)
{
	hitter = bow;
}
