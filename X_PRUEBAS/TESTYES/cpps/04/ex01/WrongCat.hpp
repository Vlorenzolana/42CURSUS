/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:40:34 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/17 17:38:10 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string	type;
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();
		
		WrongCat&	operator = (const WrongCat& other);
		void		makeSound() const;
};

#endif