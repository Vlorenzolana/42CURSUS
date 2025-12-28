/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:20:28 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:20:31 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int	main()
{
	Animal *a = new Animal();
	a->makeSound();
	delete a;
	std::cout << std::endl;
	
	Animal	*b = new Dog();
	b->makeSound();
	delete b;
	std::cout << std::endl;
	
	Animal	*c = new Cat();
	c->makeSound();
	delete c;
	std::cout << std::endl;

	WrongAnimal *w = new WrongCat();
	w->makeSound();
	delete w;
		
	return (0);
}

/* int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

return 0;
} */