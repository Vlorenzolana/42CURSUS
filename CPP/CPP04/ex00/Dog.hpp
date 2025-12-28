/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:20:34 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:20:36 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:

	protected:

	public:
		Dog();
		Dog(const Dog& original);
		~Dog();

		Dog&	operator=(const Dog& other);
		
		void makeSound() const;
};

