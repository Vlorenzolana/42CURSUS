/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:40:34 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/24 12:42:23 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		std::string	type;
		Brain*		brain;
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();
		
		Dog&	operator = (const Dog& other);
		void	makeSound() const;
};

#endif