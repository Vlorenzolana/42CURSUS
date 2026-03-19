/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:05:40 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/18 20:05:42 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name(name), grade(grade)
{
    if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.name), grade(other.grade)
{
    if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
		if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name << " couldn’t execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

void	Bureaucrat::signForm(AForm& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name << " couldnt sign " << f.getName()
			<< " because " << e.what() << std::endl;
	}
}

