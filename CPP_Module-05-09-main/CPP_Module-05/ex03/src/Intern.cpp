/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:59:29 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/12 15:30:12 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}


AForm* robotomy(std::string name) { return (new RobotomyRequestForm(name)); }

AForm* presidential(std::string name) { return (new PresidentialPardonForm(name)); }

AForm* shrubbery(std::string name) { return (new ShrubberyCreationForm(name)); }

AForm* Intern::makeForm(std::string formName, std::string target)
{
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*forms[3])(std::string) = {
		shrubbery,
		robotomy,
		presidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i](target);
		}
	}

	std::cout << "Error: form " << formName << " does not exist" << std::endl;
	return NULL;
}


std::ostream& operator<<(std::ostream& os, const Intern& f)
{
	(void) f;
	os << "Intern";
	return os;
}
