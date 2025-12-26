/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:31:02 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:31:04 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "zombie.hpp"

void	randomChump( std::string argv2 )
{
	Zombie	stalker(argv2);			//	Zombie 'stalker' is allocated on the STACK. When randomChump() finishes, 'stalker' is automatically destroyed.
}
