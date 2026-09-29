/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:47:35 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 12:38:38 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:

		std::string	_name;
		Weapon		&hitter;

	public:
	
		HumanA(std::string name, Weapon &hitter);
		~HumanA();
	
		void	attack(void);
};
