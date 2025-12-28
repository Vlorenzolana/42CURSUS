/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:14:58 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:53:48 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:

	protected:
	
		FragTrap();

	public:

		FragTrap(std::string callsign);
		FragTrap(const FragTrap& model);
		~FragTrap();

		FragTrap& operator=(const FragTrap& other);

		void	attack(const std::string& target);
		void	highFivesGuys();
};

