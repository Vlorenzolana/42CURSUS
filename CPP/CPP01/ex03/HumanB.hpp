/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:48:04 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:48:05 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:

		std::string	_name;
		Weapon		*hitter;

	public:
	
		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon *bow);
		void	attack(void);
};