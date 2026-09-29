/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:48:24 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:48:26 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
	private:
	
		std::string _type;

	public:

		Weapon(std::string w_type);
		~Weapon();

		std::string	getType() const;
		void	setType(std::string new_type);
};
