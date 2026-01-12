/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:24:47 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/12 18:15:11 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

		ScavTrap();
		//	SCAVTRAP POSESSES ALL ATTRIBUTES (_name, _hit_points, etc ...) FROM CLAPTRAP, BUT CANNOT ACCESS THEM SICE THEY ARE PRIVATE
		//	Attributes must not be redeclared, but have to be set via public setters from the ClapTrap class which ScavTrap can access.

	public:
	
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& model);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);
		
		void	attack(const std::string& target);
		void	guardGate();

};