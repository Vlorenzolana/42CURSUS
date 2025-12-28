/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:22:17 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:22:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		void	makeSound() const;
		const Brain* getBrain() const;		// Returns a const pointer to the Brain
};

