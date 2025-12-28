/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:33:41 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/29 17:48:53 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream> //cout, cin, endl
# include <string>   //.substr(), .lenght()

class Contact
{
  private:
	/*ATRIBUTOS o variables*/
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

  public:
	/*constructor y destructor(funcion para incializar atributos)*/
	Contact();
	~Contact();

	/*SETTERS*/
	void set_first_name(const std::string &firstname);
	void set_last_name(const std::string &lastname);
	void set_nickname(const std::string &nickname);
	void set_phone_number(const std::string &phone_number);
	void set_darksecret(const std::string &darksecret);
	/*GETTERS*/
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_number_phone() const;
	std::string get_darksecret() const;
};

#endif