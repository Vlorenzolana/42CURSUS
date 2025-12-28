/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:08:27 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:53:52 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int	main()
{
/* 	std::cout << std::endl;
	std::cout << "Testing ClapTrap:" << std::endl;
	ClapTrap fred("Fred");
	fred.attack("a dummie");
	fred.takeDamage(5);
	fred.beRepaired(5);
	std::cout << std::endl; */

/* 	std::cout << "Testing ScavTrap:" << std::endl;
	ScavTrap bill("Bill");
	bill.attack("a dummie");
	bill.takeDamage(20);
	bill.beRepaired(5);
	bill.guardGate();
	std::cout << std::endl; */

/* 	std::cout << "Testing FragTrap:" << std::endl;
	FragTrap charlie("Charlie");
	charlie.attack("some chump");
	charlie.takeDamage(20);
	charlie.beRepaired(5);
	charlie.highFivesGuys();
	std::cout << std::endl; */

	std::cout << "Testing DiamondTrap:" << std::endl;
	DiamondTrap	louie("Louie");
	louie.ScavTrap::attack("with blind rage");				//	Ambiguity solved by explicit choice. We could use "using ScavTrap::attack;" in the class declaration.
	//louie.FragTrap::attack("a weak spot");				//	Also we could override the attack() with DiamondTrap's own attack().
	//louie.ClapTrap::attack("an unshielded enemy");
	louie.takeDamage(20);
	louie.beRepaired(5);
	louie.guardGate();
	louie.highFivesGuys();
	louie.whoAmI();
	std::cout << std::endl;
	
	std::cout << "Destroying all:" << std::endl;
	return (0);
}