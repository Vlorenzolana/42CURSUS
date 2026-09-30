/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:21 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:42:52 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat():
	_name("Pedro Sanchez"),
	_grade(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
	_name(other._name),
	_grade(other._grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

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

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(const AForm& form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too HIGH exception");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too LOW exception");
}

std::ostream&	operator << (std::ostream &num, const Bureaucrat& other)
{
	num << other.getName();
	num << ", bureaucrat grade ";
	num << other.getGrade() << ".";

	return (num);
}
