/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:21 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:14:52 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::exeptionCheck()
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form():
	_name("Pedro Sanchez"),
	_signed(0),
	_signGrade(1),
	_execGrade(1) {}

Form::Form(const Form& other):
	_name(other._name),
	_signed(0),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	exeptionCheck();
}

Form::Form(std::string name, int gradeSing, int gradeExec):
	_name(name),
	_signed(0),
	_signGrade(gradeSing),
	_execGrade(gradeExec)
{
	exeptionCheck();
}

Form::~Form() {}

std::string	Form::getName()			const { return (_name); }
int			Form::getSigned()		const { return (_signed); }
int			Form::getSignGrade()	const { return (_signGrade); }
int			Form::getExecGrade()	const { return (_execGrade); }

void		Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = 1;
}

Form&	Form::operator = (const Form& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too HIGH exception");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too LOW exception");
}

std::ostream&	operator << (std::ostream &num, const Form& form)
{
	num << "\nName: " << form.getName();

	if (form.getSigned())
		num << "\nSigned?: Hell Yeah";
	else
		num << "\nSigned?: Oh Hell Nah";

	num << "\nSign Grade: " << form.getSignGrade();
	num << "\nExec Grade: " << form.getExecGrade();
	num << "\n";

	return (num);
}
