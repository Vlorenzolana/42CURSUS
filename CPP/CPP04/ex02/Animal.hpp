/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:23:19 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:23:25 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define ANIMAL_HPP

# include <iostream>

class Brain;

class Animal
{
	private:
	
	protected:
		std::string	_type;
		Animal();
		Animal(const Animal& original);

	public:
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		virtual void	makeSound() const = 0;
		virtual const Brain* getBrain() const = 0;
};

