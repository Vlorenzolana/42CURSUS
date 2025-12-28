/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:05:36 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:45:24 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:

		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_dmg;

		ClapTrap();										//	Default constructor is private so that it is not used. No ClapTrap objects without a name.
		
	public:

		ClapTrap(std::string name);						//	Custom constructor. Takes a name as parameter.
		ClapTrap(const ClapTrap& original);				//	Copy constructor.
		~ClapTrap();
		
		ClapTrap& operator=(const ClapTrap& other);		//	Copy assignment operator overload

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
