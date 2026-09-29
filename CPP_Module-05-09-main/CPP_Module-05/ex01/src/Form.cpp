/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:31:12 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/09 17:18:25 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form()
	: _name("default"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string& name, int sign, int exec)
	: _name(name), _isSigned(false), _signGrade(sign), _execGrade(exec)
{
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name),
	 _isSigned(other. _isSigned),
	 _signGrade(other._signGrade),
	 _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {}

const	std::string& Form::getName() const { return _name; }

bool	Form::getIsSigned() const { return _isSigned; }

int		Form::getSignGrade() const { return _signGrade; }

int		Form::getExecGrade() const { return _execGrade; }

void	Form::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char* Form::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream& operator<<(std::ostream&  os, const Form& f)
{
	os << "Form " << f.getName()
		<< " | signed: "<< f.getIsSigned()
		<< " | sign grade: "<< f.getSignGrade()
		<< " | exec grade: "<< f.getExecGrade();
	return os;
}



