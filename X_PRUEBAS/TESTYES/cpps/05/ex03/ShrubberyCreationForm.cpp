/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:33:00 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/13 16:56:32 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("shrubbery creation", 145, 137),
	_target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("shrubbery creation", 145, 137),
	_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other),
	_target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {return (_target);}

/*
 _______________________
|               ______  |
|              ( o    ) |
|  ______     (_____o__)|
| (  (   )     !| \\  ! |
|(________) /\  ! //    |
|  \\||//  /__\   \\/   |
|   |  |  /____\ \//    |
|  \|O |  /____\  \\    |
|___|__|____||____||____|

*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	execCheck(executor);

	std::ofstream fs((_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);

	fs << "                ______   \n";
	fs << "               ( o    )  \n";
	fs << "   ______     (_____o__) \n";
	fs << "  (  (   )     !| \\\\  !  \n";
	fs << " (________) /\\  ! //     \n";
	fs << "   \\\\||//  /__\\   \\\\/    \n";
	fs << "    |  |  /____\\ \\//     \n";
	fs << "   \\|O |  /____\\  \\\\     \n";
	fs << "____|__|____||____||_____\n";

	fs.close();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}