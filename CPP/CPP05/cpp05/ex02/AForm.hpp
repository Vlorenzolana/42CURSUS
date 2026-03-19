/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:46:09 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/03/18 19:48:46 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
	    const std::string	name;
	    bool				isSigned;
	    const int			gradeToSign;
	    const int			gradeToExecute;

    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

    const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

    void				beSigned(const Bureaucrat& b);

    virtual void		execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif