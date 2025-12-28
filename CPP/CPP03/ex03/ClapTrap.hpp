/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:05:36 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:53:34 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
	
	protected:
	
		ClapTrap();
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_dmg;
		
	public:

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& original);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	setHitPoints(int amount);
		void	setEnergyPoints(int amount);
		void	setAttackDamage(int amount);
};
