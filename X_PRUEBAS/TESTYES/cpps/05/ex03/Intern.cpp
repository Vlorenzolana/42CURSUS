/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:48:52 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:40:15 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm*	Robotomy(std::string target)		{ return (new RobotomyRequestForm(target)); }
AForm*	Shrubbery(std::string target)		{ return (new ShrubberyCreationForm(target)); }
AForm*	Presidential(std::string target)	{ return (new PresidentialPardonForm(target)); }

Intern::Intern()
{
	forms[0] = &Presidential;
	forms[1] = &Robotomy;
	forms[2] = &Shrubbery;
}

Intern::Intern(const Intern& other) {*this = other;}

Intern::~Intern() {}

AForm*	Intern::makeForm(std::string name, std::string target)
{	
	for (int i = 0; i < 3; i++)
	{
		AForm* temp = (AForm*)forms[i](target);
		if (temp->getName() == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (temp);
		}
		delete (temp);
	}
	std::cout << "Intern could not create " << name << std::endl;
	return (NULL);
}

Intern&	Intern::operator = (const Intern& other)
{
	if (this != &other)
	{
		forms[0] = &Presidential;
		forms[1] = &Robotomy;
		forms[2] = &Shrubbery;
	}
	return (*this);
}