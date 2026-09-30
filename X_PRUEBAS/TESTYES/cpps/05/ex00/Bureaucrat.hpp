/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:24:41 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/23 13:01:48 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		incGrade();
		void		decGrade();
		
		Bureaucrat&	operator = (const Bureaucrat& other);
		
		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException();
				const char* what() const throw();
		};
	
		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException();
				const char* what() const throw();
		};
	};
	
	std::ostream&	operator << (std::ostream &num, const Bureaucrat& other);
	
	#endif