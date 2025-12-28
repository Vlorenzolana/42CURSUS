/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 12:46:04 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 13:28:12 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl object constructed" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl object destroyed"	<< std::endl;
}

Harl::complaintType	Harl::getComplaintLevel(std::string level)
{
	if (level == "DEBUG")
		return Harl::DEBUG;
	else if (level == "INFO")
		return Harl::INFO;
	else if (level == "WARNING")
		return Harl::WARNING;
	else if (level == "ERROR")
		return Harl::ERROR;
	else
		return Harl::UNKNOWN;
}

void	Harl::complain(std::string level)
{
	Harl::complaintType scale;
	
	method_pointer functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	scale = getComplaintLevel(level);
	switch (scale)
	{
		case DEBUG:		
		case INFO:
		case WARNING:
		case ERROR:
			(this->*functions[scale])();
			break ;
		
		case UNKNOWN:
			break ;
	}
}

void	Harl::debug(void)
{
	std::cout << "DEBUG: This is a generic complaint. I just love complaining." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: Not getting over-the-top quality at half price will make me angry" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: I am an entitled and bossy Harl and I will treat you like scum" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: I want to speak to your manager!" << std::endl;
}
