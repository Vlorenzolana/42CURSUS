/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:01:17 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/09 16:47:34 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*horde = zombieHorde(5, "Paco");
	
	int i = 0;
	while (i < 5)
		horde[i++].announce();
	delete[](horde);
	return (0);
}
