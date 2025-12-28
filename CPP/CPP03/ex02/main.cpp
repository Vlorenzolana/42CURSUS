/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:08:27 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:47:31 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

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

	std::cout << "Testing FragTrap:" << std::endl;
	FragTrap charlie("Charlie");
	charlie.attack("some chump");
	charlie.takeDamage(20);
	charlie.beRepaired(5);
	charlie.highFivesGuys();
	std::cout << std::endl;
	
	std::cout << "Destroying all:" << std::endl;
	return (0);
}