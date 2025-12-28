/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:22:22 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:22:25 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int	main()
{
/* 	Animal *a = new Animal();
	a->makeSound();
	delete a;
	std::cout << std::endl; */
	
/* 	Animal	*b = new Dog();
	b->makeSound();
	delete b;
	std::cout << std::endl; */
	
/* 	Animal	*c = new Cat();
	c->makeSound();
	delete c;
	std::cout << std::endl; */

/* 	WrongAnimal *w = new WrongCat();
	w->makeSound();
	delete w; */

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
 	Dog* dogPtr = static_cast<Dog*>(z[1]);		//	Declare a pointer Dog* and cast z[1] to it because	Dog copy constructor needs (const Dog& original)	
	Animal* clonedog = new Dog(*dogPtr);		//	Now create the deep copy; 
	clonedog->makeSound();
	std::cout << "Clonedog has this idea: " << clonedog->getBrain()->ideas[42] << std::endl;
	std::cout << std::endl;
	Cat* catPtr = static_cast<Cat*>(z[4]);		//	Same process but with cat.
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
	
	return (0);
}