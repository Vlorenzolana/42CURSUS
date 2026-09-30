/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:05:31 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/20 14:17:14 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain full of Cheeeeeeeeeeeeeese" << std::endl;
	for (int i = 0; i < 100; i ++)
		_ideas[i] = "Cheeeeeeeeeeeeeese";
}

Brain::Brain(std::string newIdeas)
{
	std::cout << "Brain full of " + newIdeas << std::endl;
	for (int i = 0; i < 100; i ++)
		_ideas[i] = newIdeas;
}

Brain::Brain(const Brain& other) { *this = other; }

Brain::~Brain() { std::cout << "Brain fucking explodes" << std::endl; }

Brain&	Brain::operator = (const Brain& other)
{
	if (this != &other)
		for (int i = 0; i < 100; i ++)
			_ideas[i] = other._ideas[i];
	return  (*this);
}

const std::string* Brain::getIdeas() const	{ return _ideas; }
