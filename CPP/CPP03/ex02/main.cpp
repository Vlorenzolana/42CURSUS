/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:26:01 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/11 00:23:06 by vlorenzo         ###   ########.fr       */
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
	std::cout << std::endl;
 */
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
	charlie.takeDamage(100);
	charlie.beRepaired(0);
	charlie.highFivesGuys();
	std::cout << std::endl;
	
	std::cout << "Destroying all:" << std::endl;
	return (0);
}

/* 
Charlie	FragTrap	~FragTrap() + ~ClapTrap()
Bill	ScavTrap	~ScavTrap() + ~ClapTrap()
Fred	ClapTrap	~ClapTrap() 
*/