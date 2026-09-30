/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:27:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:34:47 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iomanip>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

int main()
{
	Bureaucrat				paco("sebas", 40);
	RobotomyRequestForm		a32("House");

	std::cout << HBLU << paco << RST << std::endl;
	std::cout << HMAG << a32 << RST << std::endl;

	paco.executeForm(a32);
	paco.signForm(a32);
	paco.executeForm(a32);

	std::cout << HMAG << a32 << RST << std::endl;
	
	return (0);
};