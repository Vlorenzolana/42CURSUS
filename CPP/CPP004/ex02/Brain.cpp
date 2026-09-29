/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:23:30 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:23:32 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor created" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Default idea";
}

Brain::Brain(const Brain& model)
{
	std::cout << "Brain copy constructor created" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = model.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor created" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}