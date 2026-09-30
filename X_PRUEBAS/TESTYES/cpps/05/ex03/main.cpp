/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:27:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:41:51 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

int main()
{
	Bureaucrat	paco("sebas", 1);
	Intern		pepe;
	AForm*		a32 = pepe.makeForm("NOT VALID", "THREE");
	a32 = pepe.makeForm("presidential pardon", "ONE");
	AForm*		a33 = pepe.makeForm("shrubbery creation", "TWO");
	AForm*		a34 = pepe.makeForm("robotomy request", "THREE");

	std::cout << HBLU << paco << RST << std::endl;
	std::cout << HMAG << *a32 << RST << std::endl;
	std::cout << HMAG << *a33 << RST << std::endl;
	std::cout << HMAG << *a34 << RST << std::endl;

	paco.executeForm(*a32);
	paco.executeForm(*a33);
	paco.executeForm(*a34);
	paco.signForm(*a32);
	paco.signForm(*a33);
	paco.signForm(*a34);
	paco.executeForm(*a32);
	paco.executeForm(*a33);
	paco.executeForm(*a34);

	std::cout << HMAG << *a32 << RST << std::endl;
	std::cout << HMAG << *a33 << RST << std::endl;
	std::cout << HMAG << *a34 << RST << std::endl;
	
	delete (a32);
	delete (a33);
	delete (a34);

	return (0);
};