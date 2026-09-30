/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:52:09 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/29 14:11:25 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "Character.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice&	operator = (const Ice& other);
		Ice*	clone() const;
		void	use(ICharacter& target);
};

#endif