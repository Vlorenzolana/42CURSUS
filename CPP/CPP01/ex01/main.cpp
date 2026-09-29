/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:45:59 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 12:46:02 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie *horde;
	
	if (argc != 3)
	{
		std::cout << "Usage: ./horde <nº_of_zombies> <zombie_name>" << std::endl;
		return (1);
	}
	horde = zombieHorde(atoi(argv[1]), argv[2]);
	if (horde == NULL)
    {
        std::cout << "Horde creation failed!" << std::endl;
        return (1);
    }
	delete[] horde;
	return (0);
}

