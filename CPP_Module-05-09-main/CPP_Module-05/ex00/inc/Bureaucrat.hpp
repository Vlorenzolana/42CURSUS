/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:34:17 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/09 13:20:18 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		std::string _Name;
		int		_Grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const 	std::string& getName() const;
		int 	getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw () { return "Grade too high"; }
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw () { return "Grade too low"; }
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object);

#endif