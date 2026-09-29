/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:07:52 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/12 15:47:18 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main() 
{
	std::cout << "===== BUREAUCRATS CREATION =====" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat senior("Senior", 50);
	Bureaucrat junior("Junior", 150);

	std::cout << boss << std::endl;
	std::cout << senior << std::endl;
	std::cout << junior << std::endl;
	
	std::cout << std::endl;

	std::cout << "===== FORMS CREATION =====" << std::endl;

	AForm* shrub = new ShrubberyCreationForm("home");
	AForm* robot = new RobotomyRequestForm("Bender");
	AForm* pardon = new PresidentialPardonForm("Arthur Dent");

	std::cout << *shrub << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *pardon << std::endl;

	std::cout << std::endl;

	std::cout << "===== JUNIOR TRIES TO SIGN =====" << std::endl;

	junior.signForm(*shrub);
	junior.signForm(*robot);
	junior.signForm(*pardon);

	std::cout << std::endl;

	std::cout << "===== SENIOR SIGN AND EXECUTE SOME STUFF =====" << std::endl;

	senior.signForm(*shrub);
	senior.executeForm(*shrub);
	std::cout << "---" << std::endl;
	senior.signForm(*robot);
	senior.executeForm(*robot);
	std::cout << "---" << std::endl;
	senior.signForm(*pardon);
	senior.executeForm(*pardon);

	std::cout << std::endl;

	std::cout << "===== SIGNED BY THE BOSS =====" << std::endl;

	boss.signForm(*shrub);
	boss.signForm(*robot);
	boss.signForm(*pardon);

	std::cout << std::endl;

	std::cout << "===== INTERN TRIES TO EXECUTE =====" << std::endl;

	junior.executeForm(*shrub);
	junior.executeForm(*robot);
	junior.executeForm(*pardon);

	std::cout << std::endl;

	std::cout << "===== BOSS EXECUTE THE REST =====" << std::endl;

	boss.executeForm(*robot);
	std::cout << "---" << std::endl;
	boss.executeForm(*pardon);

	std::cout << std::endl;

	delete shrub;
	delete robot;
	delete pardon;

	return 0;
}