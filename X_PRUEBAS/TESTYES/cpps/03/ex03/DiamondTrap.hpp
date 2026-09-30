/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:29:25 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/17 12:55:15 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	name;
	
	public:
		DiamondTrap();
		DiamondTrap(std::string newName);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();

		DiamondTrap&	operator = (const DiamondTrap& other);
	
		void whoAmI();
};

#endif