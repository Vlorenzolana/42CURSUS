/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:30:56 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 10:47:50 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "zombie.hpp"

Zombie *newZombie(std::string argv1)
{
	Zombie	*walker;
	
	walker = new Zombie(argv1);
	return (walker);
}
