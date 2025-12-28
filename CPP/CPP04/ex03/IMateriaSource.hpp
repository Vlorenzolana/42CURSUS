/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:27:16 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:27:18 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include <iostream>

class IMateriaSource
{
	private:
		IMateriaSource(const IMateriaSource& original);
		IMateriaSource& operator=(const IMateriaSource& other);

	protected:
		IMateriaSource() {};

	public:

		virtual ~IMateriaSource() {}										//	Public declaration of destructor is crucial for proper polymorphic cleanup when deleting objects through a base pointer.
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & _type) = 0;
};
