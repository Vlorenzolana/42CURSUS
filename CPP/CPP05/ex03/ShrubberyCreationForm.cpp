/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:12:33 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/31 14:10:57 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream	out((target + "_shrubbery").c_str());
	if (!out)
		return;

	out << "         /\\       " << std::endl;
	out << "       //_-_\\     " << std::endl;
	out << "     //~~   ~~\\   " << std::endl;
	out << "   //~~      ~~\\  " << std::endl;
	out << "   {~   ~~ ~~  ~}  " << std::endl;
	out << "    \\_-    -_//   " << std::endl;
	out << "        \\ //      " << std::endl;
	out << "        | |       " << std::endl;
	out << "        | |       " << std::endl;
	out << "      //// \\\\    " << std::endl;
	out << "    ////// \\\\\\  " << std::endl;

	out.close();
}