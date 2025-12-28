/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:26:58 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:27:00 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure(const Cure& original);
		~Cure();

		Cure& operator=(const Cure& other);

		Cure* clone() const;
		void use(ICharacter& target);
};
