/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:35:29 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/09 18:01:27 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat(): _Name("default"), _Grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _Name(name), _Grade(grade)
{
	if (_Grade < 1) { throw Bureaucrat::GradeTooHighException(); }
	if (_Grade > 150) {throw Bureaucrat::GradeTooLowException(); }
}
Bureaucrat::Bureaucrat(const Bureaucrat& other): _Name(other._Name), _Grade(other._Grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) {_Grade = other._Grade; }
	return *this;
}

Bureaucrat::~Bureaucrat () {}

const	std::string& Bureaucrat::getName() const { return _Name; }

int 	Bureaucrat::getGrade() const { return _Grade; }

void	Bureaucrat::incrementGrade()
{
	if (_Grade - 1 < 1) { throw Bureaucrat::GradeTooHighException(); }
	_Grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_Grade + 1 > 150) { throw Bureaucrat::GradeTooLowException(); }
	_Grade++;
}

void Bureaucrat::signForm(Form& form) 
{
	try
	{
		form.beSigned(*this);
		std::cout << _Name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _Name << " couldn’t sign "
		<< form.getName()
		<< " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object)
{
	os << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return os;
}
