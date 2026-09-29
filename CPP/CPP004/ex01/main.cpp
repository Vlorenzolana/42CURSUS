/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:22:22 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/31 14:51:25 by vlorenzo         ###   ########.fr       */
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

/* int main()
{
	std::cout << "=== TEST 1: Basic polymorphism ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "=== TEST 2: Array of Animals (half Dogs, half Cats) ===" << std::endl;
	Animal *animals[6];
	for (int k = 0; k < 3; k++)
		animals[k] = new Dog();
	for (int k = 3; k < 6; k++)
		animals[k] = new Cat();
	
	for (int k = 0; k < 6; k++)
	{
		std::cout << "Animal " << k << " (" << animals[k]->getType() << "): ";
		animals[k]->makeSound();
	}
	std::cout << std::endl;

	std::cout << "=== TEST 3: Deep copy test (Dog) ===" << std::endl;
	{
		Dog originalDog;
		Dog copyDog(originalDog);	// Copy constructor - deep copy
		std::cout << "Original Dog Brain address: " << originalDog.getBrain() << std::endl;
		std::cout << "Copy Dog Brain address: " << copyDog.getBrain() << std::endl;
		std::cout << "(Different addresses = deep copy is working!)" << std::endl;
		std::cout << "Original idea[0]: " << originalDog.getBrain()->ideas[0] << std::endl;
		std::cout << "Copy idea[0]: " << copyDog.getBrain()->ideas[0] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 4: Deep copy test (Cat) ===" << std::endl;
	{
		Cat originalCat;
		Cat copyCat(originalCat);	// Copy constructor - deep copy
		std::cout << "Original Cat Brain address: " << originalCat.getBrain() << std::endl;
		std::cout << "Copy Cat Brain address: " << copyCat.getBrain() << std::endl;
		std::cout << "(Different addresses = deep copy is working!)" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 5: Assignment operator test ===" << std::endl;
	{
		Dog dog1;
		Dog dog2;
		std::cout << "Dog1 Brain address before: " << dog1.getBrain() << std::endl;
		std::cout << "Dog2 Brain address before: " << dog2.getBrain() << std::endl;
		dog2 = dog1;	// Assignment operator
		std::cout << "Dog2 Brain address after assignment: " << dog2.getBrain() << std::endl;
		std::cout << "(dog2 has new Brain, not pointing to dog1's Brain)" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 6: WrongAnimal (no polymorphism) ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "WrongAnimal makeSound: ";
	wrongMeta->makeSound();
	std::cout << "WrongCat through WrongAnimal* makeSound: ";
	wrongCat->makeSound();
	std::cout << "(Both make WrongAnimal sound - no virtual!)" << std::endl;
	
	delete wrongMeta;
	delete wrongCat;
	std::cout << std::endl;

	std::cout << "=== TEST 7: Deleting array of Animals ===" << std::endl;
	for (int k = 0; k < 6; k++)
		delete animals[k];
	std::cout << "All animals deleted! No memory leaks!" << std::endl;
}
 */