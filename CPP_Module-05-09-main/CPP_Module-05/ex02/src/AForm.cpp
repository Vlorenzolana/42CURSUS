/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:28:32 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/10 18:41:32 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _isSigned(false), _signGrade(sign), _execGrade(exec)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	_isSigned = other._isSigned;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

int	AForm::getSignGrade(void) const { return (_signGrade); }

int	AForm::getExecGrade(void) const { return (_execGrade); }

std::string AForm::getName(void) const { return (_name); }

bool AForm::getIsSigned(void) const { return (_isSigned); }

void AForm::beSigned(const Bureaucrat& obj)
{
	if (_isSigned == true)
		throw AForm::FormAlreadySignedException();
	if (obj.getGrade() > this -> getSignGrade())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm " << f.getName()
		<< " | signed: "<< f.getIsSigned()
		<< " | sign grade: "<< f.getSignGrade()
		<< " | exec grade: "<< f.getExecGrade();
	return os;
}
