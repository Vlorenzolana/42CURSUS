/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:25:49 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/01/11 00:22:27 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

		FragTrap();

	public:

		FragTrap(std::string callsign);
		FragTrap(const FragTrap& model);
		~FragTrap();

		FragTrap& operator=(const FragTrap& other);

		void	attack(const std::string& target);
		void highFivesGuys(void);
};
