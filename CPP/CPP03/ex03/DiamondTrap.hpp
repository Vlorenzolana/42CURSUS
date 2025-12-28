/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:21:46 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:53:39 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:

		std::string	_name;
		DiamondTrap();

	public:

		DiamondTrap(std::string callsign);
		DiamondTrap(const DiamondTrap& model);
		~DiamondTrap();
	
		DiamondTrap& operator=(const DiamondTrap& other);

		//using ScavTrap::attack;
		
		void	whoAmI();
};

