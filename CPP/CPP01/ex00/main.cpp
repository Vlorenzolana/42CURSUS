/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:30:51 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 12:07:18 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie *walker;
	
	if (argc != 3)
	{
		std::cout << "Usage: ./brainz <zombie_name> <ramdomchump_name>" << std::endl;
		return (1);
	}
	walker = newZombie(argv[1]);
	randomChump(argv[2]);
	delete walker;

	return (0);
}
