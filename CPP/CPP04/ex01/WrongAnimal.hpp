/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:22:37 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:22:38 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	private:

	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& original);
		~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& other);

		void	makeSound();
};