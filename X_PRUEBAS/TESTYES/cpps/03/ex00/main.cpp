/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:27:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/16 15:42:47 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	enemy1;
	ClapTrap	enemy2("Squidward");
	ClapTrap	enemy3(enemy2);
	
	enemy1.takeDamage(9);
	enemy1.beRepaired(1);
	enemy1.takeDamage(1);
	enemy1.takeDamage(1);
	enemy1.takeDamage(1);
	
	enemy2.attack("your mom");
	enemy2.attack("your mom");
	enemy2.attack("your mom");
	enemy2.attack("your mom");
	enemy2.attack("your mom");
	enemy2.attack("your mom");
	enemy2.attack("your mom");
	enemy2.attack("your mom");
	enemy2.attack("your mom");
	enemy2.attack("your mom");

	enemy2.attack("your mom");
	enemy3.attack("your mom");
	
	return (0);
}
