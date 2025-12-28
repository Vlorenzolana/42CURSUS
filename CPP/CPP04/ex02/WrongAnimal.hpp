/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:26:19 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:26:21 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	private:
		std::string	_sound;

	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& original);
		~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& other);

		void	makeSound();
		void	setSound(const std::string new_sound);
};