/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:46:13 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:46:16 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define ZOMBIE_HPP

# include <iostream>
# include <cstdlib>

class	Zombie
{
	private:

		std::string	_name;

	public:
		
		Zombie();
		~Zombie();
		
		void	announce( void );
		void	setName(std::string name);
	
};

Zombie	*zombieHorde(int n, std::string argv2);
