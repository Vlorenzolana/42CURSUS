/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:07:52 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/12 15:49:56 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

static void section(const std::string& title)
{
	std::cout << "\n==================== " << title << " ====================\n\n";
}

int main()
{
	section("BUREAUCRATS CREATION");

	Bureaucrat junior("Junior", 150);
	Bureaucrat senior("Senior", 50);
	Bureaucrat boss("Boss", 1);

	std::cout << junior << std::endl;
	std::cout << senior << std::endl;
	std::cout << boss << std::endl;

	section("INTERN CREATION");

	Intern intern;

	section("INTERN CREATES FORMS");

	AForm* robot = intern.makeForm("robotomy request", "Bender");
	AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
	AForm* shrub = intern.makeForm("shrubbery creation", "Home");
	AForm* unknown = intern.makeForm("unknown form", "Nobody");

	section("SIGNING & EXECUTION TESTS");

	// ---- Robotomy ----
	if (robot)
	{
		std::cout << *robot << std::endl;
		junior.signForm(*robot);   // should fail
		senior.signForm(*robot);   // should succeed
		senior.executeForm(*robot); // may fail (grade)
		boss.executeForm(*robot);   // should succeed
	}

	// ---- Presidential Pardon ----
	if (pardon)
	{
		std::cout << "\n" << *pardon << std::endl;
		senior.signForm(*pardon);  // should fail
		boss.signForm(*pardon);    // should succeed
		senior.executeForm(*pardon); // should fail
		boss.executeForm(*pardon);   // should succeed
	}

	// ---- Shrubbery ----
	if (shrub)
	{
		std::cout << "\n" << *shrub << std::endl;
		boss.signForm(*shrub);
		boss.executeForm(*shrub);  // creates file
	}

	section("CLEANUP");

	delete robot;
	delete pardon;
	delete shrub;
	delete unknown;

	std::cout << "All forms deleted.\n";

	return 0;
}
