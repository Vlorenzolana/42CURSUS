/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:45:54 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:26:31 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequest", 72, 45),
	_target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequest", 72, 45),
	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other),
	_target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {return (_target);}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	execCheck(executor);
	
	std::cout << "FRRRRRRRRRRRRR..." << std::endl; sleep(1);
	std::cout << "FRRRRRRRRRRRRR..." << std::endl; sleep(1);
	std::cout << "FRRRRRRRRRRRRR..." << std::endl; sleep(1);
	std::cout << "FRRRRRRRRRRRRR..." << std::endl; sleep(1);
	srand (time(NULL));
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized!" << std::endl;
	else
		 std::cout << getTarget() << " robotomy failed :(" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator = (const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}