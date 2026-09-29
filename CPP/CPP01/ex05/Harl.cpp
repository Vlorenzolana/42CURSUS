/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 12:46:04 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/30 16:52:02 by vlorenzo         ###   ########.fr       */
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

void Harl::complain(const std::string& level)
{
    const std::array<std::string, 4> complains = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (size_t i = 0; i < complains.size(); ++i)
        if (level == complains[i])
            return (this->*functions[i])();
}

void	Harl::debug(void) const
{
    std::cout << "DEBUG: This is a generic complaint. I just love complaining." << std::endl;
}

void	Harl::info(void) const
{
    std::cout << "INFO: Not getting over-the-top quality at half price will make me angry" << std::endl;
}

void	Harl::warning(void) const
{
    std::cout << "WARNING: I am an entitled and bossy Harl and I will treat you like scum" << std::endl;
}

void	Harl::error(void) const
{
    std::cout << "ERROR: I want to speak to your manager!" << std::endl;
}
