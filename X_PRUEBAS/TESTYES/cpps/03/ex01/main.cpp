/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:27:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/07 12:48:58 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	enemy1;
	ScavTrap	enemy2("Squidward");
	ScavTrap	enemy3(enemy2);
	
	enemy1.takeDamage(99);
	enemy1.beRepaired(1);
	enemy1.takeDamage(1);
	enemy1.takeDamage(1);
	enemy1.takeDamage(1);
	
	for (int i = 0; i <= 50; i++)
        enemy2.attack("your mum");

	enemy3.attack("your mom");
	enemy3.guardGate();
	
	return (0);
}
