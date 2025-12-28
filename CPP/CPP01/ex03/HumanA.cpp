/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:47:26 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 12:38:47 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &hitter): _name(name), hitter(hitter)
{
	std::cout << "Spawned HumanA " << _name << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << _name << " has fled the battle" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << hitter.getType() << std::endl;
}
