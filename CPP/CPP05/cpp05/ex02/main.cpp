/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:44:38 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/18 19:44:58 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Creating a Bureaucrat ===" << std::endl;
    Bureaucrat boss("Boss", 45);
    std::cout << boss << std::endl;

    std::cout << "\n=== Creating a Form ===" << std::endl;

    //PresidentialPardonForm form("Arthur Dent");
    //ShrubberyCreationForm form("home");
     RobotomyRequestForm form("Bender");

    std::cout << form << std::endl;

    std::cout << "\n=== Trying to execute WITHOUT signing ===" << std::endl;
    try
    {
        boss.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Signing the form ===" << std::endl;
    boss.signForm(form);

    std::cout << "\n=== Executing the form ===" << std::endl;
    boss.executeForm(form);

    std::cout << "\n=== Final state ===" << std::endl;
    std::cout << form << std::endl;

    return 0;
}