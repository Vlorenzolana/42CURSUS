/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:24:32 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/12 18:21:54 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int	main()
{
	std::cout << "Testing ScavTrap:" << std::endl;
	ScavTrap bill("Bill");
	bill.attack("a dummie");							//	ScavTrap attack method.
	bill.ClapTrap::attack("a training post");			//	Inherited attack method. 
	bill.takeDamage(42);
	bill.beRepaired(5);
	bill.guardGate();
	std::cout << std::endl;

	std::cout << "Destroying all:" << std::endl;
	return (0);
}

/* 	
//  Tests
	std::cout << "Testing ClapTrap:" << std::endl;
	ClapTrap fred("Fred");
	fred.attack("a random target");				//	ClapTrap attack method.
	fred.takeDamage(5);
	fred.beRepaired(5);
	std::cout << std::endl; */