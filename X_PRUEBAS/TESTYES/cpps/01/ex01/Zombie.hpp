/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:37:08 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/09 16:43:36 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class	Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		void	nameSet(std::string name);
		void	announce(void);	
};

Zombie*	zombieHorde(int N, std::string name);

#endif