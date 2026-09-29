/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:07:56 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/10 13:41:12 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm();
		AForm(std::string name, int sign, int exec);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		int				getExecGrade(void) const;
		int				getSignGrade(void) const;
		bool			getIsSigned(void) const;
		std::string		getName(void) const;
		void			beSigned(const Bureaucrat& obj);
		virtual void	execute(const Bureaucrat& obj) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Grade too low");
				}
		};

		class FormNotSignedException : public std::exception
		{
			public :
				virtual const char* what() const throw()
				{
					return ("Error : Form not signed");
				}
		};

		class FormAlreadySignedException : public std::exception
		{
			public :
				virtual const char* what() const throw()
				{
					return ("Error : Form already signed");
				}
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& object);

#endif