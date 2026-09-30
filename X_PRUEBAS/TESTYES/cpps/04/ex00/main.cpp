/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:27:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/17 17:31:20 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal*		Shapeshifter = new Animal();
	const Animal*		Doggo = new Dog();
	const Animal*		Kittie = new Cat();
	const WrongAnimal*	NotKittie = new WrongCat();
	
	Shapeshifter->makeSound();
	Doggo->makeSound();
	Kittie->makeSound();
	NotKittie->makeSound();

	std::cout << Shapeshifter->getType() << std::endl;
	std::cout << Doggo->getType() << std::endl;
	std::cout << Kittie->getType() << std::endl;
	std::cout << NotKittie->getType() << std::endl;

	delete Shapeshifter;
	delete Doggo;
	delete Kittie;
	delete NotKittie;
	
	return (0);
}
