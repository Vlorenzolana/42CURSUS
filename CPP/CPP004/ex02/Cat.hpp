/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:23:45 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/14 18:42:38 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
	
		Brain* _cerebellum;

	protected:

	public:
		Cat();
		Cat(const Cat& original);
		~Cat();

		Cat&	operator=(const Cat& other);

		void        makeSound() const;
		const Brain* getBrain() const;
};