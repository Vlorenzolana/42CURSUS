/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:46:02 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/12 20:09:58 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("presidential pardon", 25, 5),
	_target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("presidential pardon", 25, 5),
	_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other),
	_target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const {return (_target);}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	execCheck(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator = (const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}