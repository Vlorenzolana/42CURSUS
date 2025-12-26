/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:46:07 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:46:10 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << "A zombie has spawned!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "A zombie has been destroyed!" << std::endl;
}

void	Zombie::setName(std::string input)
{
	_name = input;
}
