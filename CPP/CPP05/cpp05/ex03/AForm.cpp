/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:04:45 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/18 20:04:47 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false),
	  gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm()
{
}

const std::string&	AForm::getName() const
{
	return name;
}

bool	AForm::getIsSigned() const
{
	return isSigned;
}

int	AForm::getGradeToSign() const
{
	return gradeToSign;
}

int	AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "form grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "form grade too low";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "form not signed";
}

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << "Form " << f.getName();
	os << ", signed: ";
	if (f.getIsSigned())
		os << "true";
	else
		os << "false";
	os << ", grade to sign: " << f.getGradeToSign();
	os << ", grade to execute: " << f.getGradeToExecute();
	return os;
}
