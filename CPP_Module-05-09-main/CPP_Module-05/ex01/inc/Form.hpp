/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:30:56 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/02/09 18:02:38 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class	Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	
	public:
		Form();
		Form(const std::string& name, int sign, int exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const	std::string& getName()	const;
		bool	getIsSigned() 			const;
		int		getSignGrade()			const;
		int		getExecGrade()			const;

		void	beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
