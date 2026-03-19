/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:08:12 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/18 20:08:21 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

static void	signAndExecute(Bureaucrat& boss, AForm* form)
{
	if (!form)
		return;
	boss.signForm(*form);
	boss.executeForm(*form);
}

int	main()
{
	Intern		intern;
	Bureaucrat	boss("Boss", 1);

	AForm*	f1 = intern.makeForm("robotomy request", "Bender");
	AForm*	f2 = intern.makeForm("shrubbery creation", "home");
	AForm*	f3 = intern.makeForm("presidential pardon", "Arthur Dent");
	AForm*	f4 = intern.makeForm("unknown form", "target");

	signAndExecute(boss, f1);
	signAndExecute(boss, f2);
	signAndExecute(boss, f3);
	signAndExecute(boss, f4);

	delete f1;
	delete f2;
	delete f3;
	delete f4;

	return 0;
}
