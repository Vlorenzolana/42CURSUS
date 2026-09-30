/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:40:05 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/09 15:29:27 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	Zombie::name = name;
}

Zombie::~Zombie()
{
	//std::cout << Zombie::name + ": Mooore braiiiiiinz I want...\n";
	std::cout << "*shotgun noises*\n";
	std::cout << Zombie::name + ": Fucking dies" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << Zombie::name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}