/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:31:11 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 11:58:38 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:

		std::string	_name;
				
	public:
		
		Zombie(std::string name);
		~Zombie();
		void announce( void );
};

void randomChump( std::string name );
Zombie *newZombie(std::string name);
