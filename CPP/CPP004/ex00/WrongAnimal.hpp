/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:20:21 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/14 18:45:13 by vlorenzo         ###   ########.fr       */
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
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& other);

		std::string	getType() const;
		void		makeSound() const;
};