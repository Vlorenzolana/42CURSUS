/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:57:59 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:47:37 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		//	SCAVTRAP POSESSES ALL ATTRIBUTES (_name, _hit_points, etc ...) FROM CLAPTRAP, BUT CANNOT ACCESS THEM SICE THEY ARE PRIVATE
		//	Attributes must not be redeclared, but have to be set via public setters from the ClapTrap class which ScavTrap can access.
		ScavTrap();
				
	public:

		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& model);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);
		
		void	attack(const std::string& target);
		void	guardGate();
		
};

