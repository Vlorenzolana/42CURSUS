/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:21 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/11 12:04:30 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::exeptionCheck()
{
	if (_signGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150)
		throw GradeTooLowException();
	if (_execGrade < 1)
		throw GradeTooHighException();
	if (_execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm():
	_name("Pedro Sanchez"),
	_signed(0),
	_signGrade(1),
	_execGrade(1) {}

AForm::AForm(std::string name, int gradeSing, int gradeExec):
	_name(name),
	_signed(0),
	_signGrade(gradeSing),
	_execGrade(gradeExec)
{
	exeptionCheck();
}

AForm::AForm(const AForm& other):
	_name(other._name),
	_signed(0),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	exeptionCheck();
}


AForm::~AForm() {}

void AForm::execCheck(const Bureaucrat &bureaucrat) const
{
	if (_signed == 0)
		throw NotSignedException();
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}

std::string	AForm::getName()		const { return (_name); }
int			AForm::getSigned()		const { return (_signed); }
int			AForm::getSignGrade()	const { return (_signGrade); }
int			AForm::getExecGrade()	const { return (_execGrade); }

void		AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = 1;
}

AForm&	AForm::operator = (const AForm& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form NOT signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too HIGH exception");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too LOW exception");
}

std::ostream&	operator << (std::ostream &num, const AForm& AForm)
{
	num << "\nName: " << AForm.getName();

	if (AForm.getSigned())
		num << "\nSigned?: Hell Yeah";
	else
		num << "\nSigned?: Oh Hell No";

	num << "\nSign Grade: " << AForm.getSignGrade();
	num << "\nExec Grade: " << AForm.getExecGrade();
	num << "\n";

	return num;
}
