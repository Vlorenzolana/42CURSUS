/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:57:59 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:54:10 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
	
	protected:
	
		ScavTrap();

	public:

		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& model);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);
		
		void	attack(const std::string& target);
		void	guardGate();
};

