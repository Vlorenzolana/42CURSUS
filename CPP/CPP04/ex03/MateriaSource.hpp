/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:48:51 by igchurru          #+#    #+#             */
/*   Updated: 2025/07/28 16:06:46 by igchurru         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _page[4];

	protected:
	
	public:
		MateriaSource();
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const& _type);


};

