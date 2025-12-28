/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:27:07 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:27:09 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(const Ice& original);
		~Ice();

		Ice& operator=(const Ice& other);

		Ice* clone() const;
		void use(ICharacter& target);
};

