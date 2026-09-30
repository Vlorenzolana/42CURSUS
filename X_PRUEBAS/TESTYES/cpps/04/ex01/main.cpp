/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:27:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/24 12:42:37 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define	ARR_SIZE 10

int	main(void)
{
	const Animal*	Army[ARR_SIZE];
	
	for (int i = 0; i < ARR_SIZE ; i++)
	{
		if (i % 2)
			Army[i] = new Cat();
		else
			Army[i] = new Dog();
	}
	
	for (int i = 0; i < ARR_SIZE; i++)
		Army[i]->makeSound();
	
	for (int i = 0; i < ARR_SIZE; i++)
		std::cout << Army[i]->getType() << std::endl;
	
	for (int i = 0; i < ARR_SIZE; i++)
		std::cout << &Army[i] << std::endl;
	
	for (int i = 0; i < ARR_SIZE; i++)
		delete Army[i];
	
	return (0);
}
