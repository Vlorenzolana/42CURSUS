/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:24:41 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/11 11:57:56 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		void exeptionCheck(); //Not asked by the subject but its cooler
	
	public:
		Form();
		Form(const Form& other);
		Form(std::string name, int singGrade, int execGrade);
		~Form();

		std::string	getName() const;
		int			getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(const Bureaucrat &bureaucrat);

		Form&	operator = (const Form& other);

	class GradeTooHighException: public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream&	operator << (std::ostream &num, const Form& other);

#endif