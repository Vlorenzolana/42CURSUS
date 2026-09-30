/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:21 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:01:56 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Pedro Sanchez"), _grade(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName()	const { return (_name); }
int			Bureaucrat::getGrade()	const { return (_grade); }

void	Bureaucrat::incGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade --;
}

void	Bureaucrat::decGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade ++;
}

Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too HIGH exception");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too LOW exception");
}

std::ostream&	operator << (std::ostream &num, const Bureaucrat& bureaucrat)
{
	num << bureaucrat.getName();
	num << ", bureaucrat grade ";
	num << bureaucrat.getGrade() << ".";

	return num;
}
