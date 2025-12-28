/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:48:10 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 12:39:03 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Two adventurers needed for this quest!" << std::endl;
		std::cout << "Usage: ./violence <name_1> <name_2>" << std::endl;
		return (1);
	}
	
	Weapon	weap = Weapon("spiky club");
	Weapon	proj = Weapon("longbow");
	HumanA warrior = HumanA(argv[1], weap);	//	HumanA constructor MUST take a weapon. Pass a reference so that no extra weapon instances are created.

	warrior.attack();
	weap.setType("rusty sword");
	warrior.attack();

	HumanB	archer(argv[2]);				//	HumanB constructor doesn't take a weapon.
	archer.setWeapon(&proj);				//	Pass a pointer since weapon B may be empty.
	archer.attack();
	archer.setWeapon(NULL);
	archer.attack();
	
	return (0);
}
