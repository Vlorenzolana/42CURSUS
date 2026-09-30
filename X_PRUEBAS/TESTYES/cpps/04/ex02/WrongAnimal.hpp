/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:45:47 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/17 16:54:36 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAnimal_HPP
#define WRONGAnimal_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(std::string newName);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();
		
		WrongAnimal&	operator = (const WrongAnimal& other);

		void				makeSound() const;
		const std::string&	getType() const;
};

#endif