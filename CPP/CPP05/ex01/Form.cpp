/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:39:29 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/18 19:39:34 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false),
	  gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}
Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}
Form& Form::operator=(const Form& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form()
{
}
const std::string& Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}
const char* Form::GradeTooHighException::what() const throw()
{
	return "form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "form grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
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