/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:13:44 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/25 15:21:25 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_memory[4];
		
	public:
		MateriaSource();
		MateriaSource(const MateriaSource* other);
		~MateriaSource();

		MateriaSource& operator = (const MateriaSource* other);
		
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif