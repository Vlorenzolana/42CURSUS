/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:27:20 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:27:23 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	std::cout << "The grimoire has been created!" << std::endl;
	std::cout << std::endl;
	
	AMateria* iceSpell = new Ice();
	AMateria* freezeSpell = new Ice();
	src->learnMateria(iceSpell);
	std::cout << "A new spell has been added to the grimoire: " << iceSpell->getType() << std::endl;
	src->learnMateria(freezeSpell);
	std::cout << "A new spell has been added to the grimoire: " << freezeSpell->getType() << std::endl;
	std::cout << std::endl;
	
	AMateria* cureSpell = new Cure();
	AMateria* healingSpell = new Cure();
	src->learnMateria(cureSpell);
	std::cout << "A new spell has been added to the grimoire: " << cureSpell->getType() << std::endl;
	src->learnMateria(healingSpell);
	std::cout << "A new spell has been added to the grimoire: " << healingSpell->getType() << std::endl;
	std::cout << std::endl;

	AMateria* badSpell = new Ice();
	std::cout << "A wild spell appears!" << std::endl;
	src->learnMateria(badSpell);
	std::cout << std::endl;
	
	ICharacter* me = new Character("me");
	std::cout << "New character spawned: " << me->getName() << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;
	
	ICharacter* bob = new Character("bob");
	std::cout << "New character spawned: " << bob->getName() << std::endl;
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);		//	Empty slot
	me->use(3, *bob);		//	Empty slot
	std::cout << std::endl;

	me->unequip(0);
	std::cout << "Ice in slot 0 has been unequipped" << std::endl;
	me->unequip(1);
	std::cout << "Cure in slot 1 has been unequipped" << std::endl;
	std::cout << std::endl;
	
	delete bob;
	delete me;
	std::cout << std::endl;
	
	delete src;
	std::cout << std::endl;
	
	return 0;
}
