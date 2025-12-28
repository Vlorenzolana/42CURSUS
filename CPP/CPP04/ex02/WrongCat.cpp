/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:26:24 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:26:26 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
	//setSound("wrong meow meow!");
}

WrongCat::WrongCat(const WrongCat& original)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = original._type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}