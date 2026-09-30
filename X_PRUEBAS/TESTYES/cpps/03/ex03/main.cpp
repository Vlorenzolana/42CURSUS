/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:09:37 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/17 12:57:55 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	enemy1;
	DiamondTrap	enemy2("Squidward");
	DiamondTrap	enemy3(enemy2);
	
	enemy1.takeDamage(99);
	enemy1.beRepaired(1);
	enemy1.takeDamage(1);
	enemy1.takeDamage(1);
	enemy1.takeDamage(1);
	
	for (int i = 0; i <= 50; i++)
        enemy2.attack("your mum");

	enemy3.attack("your mom");
    enemy3.whoAmI();
    enemy3.guardGate();
	enemy3.highFivesGuys();
	
	return (0);
}
