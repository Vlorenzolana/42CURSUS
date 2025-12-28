/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:26:06 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:26:07 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
	
		Brain* _cerebellum;

	protected:

	public:
		Dog();
		Dog(const Dog& original);
		~Dog();

		Dog&	operator=(const Dog& other);

		void		makeSound() const;
		const Brain* getBrain() const;
};

