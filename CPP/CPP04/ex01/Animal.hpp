/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:21:49 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:21:51 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define ANIMAL_HPP

# include <iostream>

class Brain;

class Animal
{
	private:
		Brain* _genericBrain;

	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal& original);
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		std::string getType() const;

		virtual void makeSound() const;
		virtual const Brain* getBrain() const;
		
};

