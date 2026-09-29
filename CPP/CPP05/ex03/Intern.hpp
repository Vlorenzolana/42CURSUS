/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:07:34 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/18 20:07:36 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	private:
		typedef AForm* (Intern::*t_creator)(const std::string& target) const;

		AForm*	createShrubbery(const std::string& target) const;
		AForm*	createRobotomy(const std::string& target) const;
		AForm*	createPresidential(const std::string& target) const;

	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const std::string& name, const std::string& target) const;
};

#endif
