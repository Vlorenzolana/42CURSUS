/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:29:25 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/24 14:38:10 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "Character.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		Cure&	operator = (const Cure& other);
		Cure*	clone() const;
		void	use(ICharacter& target);
};

#endif