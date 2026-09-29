/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:46:19 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:46:22 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "zombie.hpp"

Zombie *zombieHorde(int argv1, std::string argv2)
{
	Zombie *horde;
	int i = 0;
	
	if (argv1 <= 0)
	{
		std::cout << "Cannot create a horde with less than 1 zombie!" << std::endl;
		return (NULL);
	}
	horde = new Zombie[argv1];
	while (i < argv1)
	{
		horde[i].setName(argv2);
		horde[i].announce();
		i++;
	}
	return (horde);
}
