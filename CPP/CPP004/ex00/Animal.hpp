/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:21:07 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:21:09 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	private:

	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal& original);
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		std::string getType() const;

		virtual void makeSound() const;
};

