/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:26:10 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/31 14:52:58 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Animal *animals[6];
	for (int k = 0; k < 3; k++)
		animals[k] = new Dog();
	for (int k = 3; k < 6; k++)
		animals[k] = new Cat();
	for (int k = 0; k < 6; k++)
		delete animals[k];

	return (0);
}

/* 
int	main()
{
	// Test: Animal abstracta, no compila
	// Animal* a = new Animal(); // ERROR: Animal es clase abstracta, no se puede instanciar

	Animal *z[6];
	for (int i = 0; i < 3; i++)
	{
		z[i] = new Dog();
		z[i]->makeSound();
		std::cout << std::endl;
	}
	for (int i = 3; i < 6; i++)
	{
		z[i] = new Cat();
		z[i]->makeSound();
		std::cout << std::endl;
	}
 	Dog* dogPtr = static_cast<Dog*>(z[1]);
	Animal* clonedog = new Dog(*dogPtr);
	clonedog->makeSound();
	std::cout << "Clonedog has this idea: " << clonedog->getBrain()->ideas[42] << std::endl;
	std::cout << std::endl;
	Cat* catPtr = static_cast<Cat*>(z[4]);
	Animal* clonecat = new Cat(*catPtr);
	clonecat->makeSound();
	std::cout << "Clonecat has this idea: " << clonecat->getBrain()->ideas[42] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
		delete z[i];
	std::cout << "All Animal Dogs and Cats have been deleted!" << std::endl;
	std::cout << std::endl;
	delete clonedog;
	delete clonecat;
	std::cout << "All clones have been deleted!" << std::endl;
} */