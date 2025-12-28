/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:08:27 by igchurru          #+#    #+#             */
/*   Updated: 2025/12/26 15:45:26 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int	main()
{
	std::cout << "Testing ClapTrap:" << std::endl;
	ClapTrap fred("Fred");
	fred.attack("a dummie");
	fred.takeDamage(5);
	fred.beRepaired(5);
	return (0);
}
