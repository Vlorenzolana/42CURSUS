/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:34:54 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/28 20:15:11 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip> // Para std::setw y std::right
# include <iostream>
# include <limits> // Para std::numeric_limits
# include <string>

# define MAX_CONTACTS 8

class Phonebook
{
  private:
	Contact _phonebook[MAX_CONTACTS];

  public:
	/*Constructor Destructor*/
	Phonebook();
	~Phonebook();

	int add_contact(std::string add);
	int search_contact(std::string search);
};

#endif
