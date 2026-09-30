/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:22:42 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:45:54 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern
{
	private:
		AForm* (*forms[3])(std::string target);
	
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		AForm*	makeForm(std::string name, std::string target);

		Intern&	operator = (const Intern& other);
};

#endif