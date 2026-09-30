/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:28:17 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/10 17:14:57 by kabasolo         ###   ########.fr       */
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

void Harl::complain(std::string level)
{
	std::string	complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int	i = -1;
	while (++i < 4)
		if (level == complains[i])
			return (this->*functions[i])();
	return ;
}
