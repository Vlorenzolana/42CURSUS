/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:24:41 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/11 13:15:57 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		void	exeptionCheck();

	protected:
		void	execCheck(const Bureaucrat &bureaucrat) const;

	public:
		AForm();
		AForm(std::string name, int singGrade, int execGrade);
		AForm(const AForm& other);
		virtual ~AForm();

		std::string	getName() const;
		int			getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(const Bureaucrat &bureaucrat);

		virtual void	execute(Bureaucrat const & executor) const = 0; //The Forms which heritage from AForm will have to define what their execute will be doing, if not, the class will not be instanciable directly

		AForm&	operator = (const AForm& other);

		class NotSignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		
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

std::ostream&	operator << (std::ostream &num, const AForm& other);

#endif