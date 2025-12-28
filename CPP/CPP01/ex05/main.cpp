/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 12:46:27 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/28 12:46:29 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int	main(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Must take exactly one argument" << std::endl;
		std::cout << "Usage: ./harl <complain_level>" << std::endl;
		return (1);
	}
	
	std::string level = argv[1];
	
	if (level.compare("DEBUG") && level.compare("INFO") && level.compare("WARNING") && level.compare("ERROR"))
	{
		std::cout << "Error: Invalid complain level" << std::endl;
		std::cout << "Valid complain levels are: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}

	Harl Karen = Harl();
	
	Karen.complain(level);

	return (0);
}
