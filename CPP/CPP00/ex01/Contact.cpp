/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:33:34 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/28 20:39:38 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp" 
#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::set_first_name(const std::string &firstname)
{
    this->_firstName = firstname;
}
void Contact::set_last_name(const std::string &lastname)
{
    this->_lastName = lastname;
}
void Contact::set_nickname(const std::string &nickname)
{
    this->_nickname = nickname;
}
void Contact::set_phone_number(const std::string &phone_number)
{
    this->_phone_number = phone_number;
}

void Contact::set_darksecret(const std::string &darksecret)
{
    this->_darkest_secret = darksecret;
}
std::string Contact::get_first_name() const {
    return _firstName;
}

std::string Contact::get_last_name() const {
    return _lastName;
}

std::string Contact::get_nickname() const {
    return _nickname;
}

std::string Contact::get_number_phone() const {
    return _phone_number;
}

std::string Contact::get_darksecret() const {
    return _darkest_secret;
}