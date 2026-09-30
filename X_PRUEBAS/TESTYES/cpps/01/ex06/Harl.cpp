/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:28:17 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/05 11:55:35 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "Debug :)" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Info :|" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Warning :/" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Error :(" << std::endl;
}

static int	whichComplain(std::string level)
{
	std::string	complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i = 0;
	while (i < 4 && level != complains[i])
		i ++;
	return (i);
}

void Harl::complain(std::string level)
{
	switch (whichComplain(level))
	{
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break ;
		default:
			std::cout << "Nothing :D" << std::endl;
	}
}
