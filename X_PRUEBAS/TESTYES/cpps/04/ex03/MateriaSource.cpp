/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:33:09 by kabasolo          #+#    #+#             */
/*   Updated: 2025/02/25 11:59:42 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource* other)
{
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i ++)
		if (_memory[i])
			delete _memory[i];
}

MateriaSource& MateriaSource::operator = (const MateriaSource* other)
{
	if (this != other)
	{
		for (int i = 0; i < 4; i ++)
		{
			if (this->_memory[i])
				delete _memory[i];
			if (other->_memory[i])
				this->_memory[i] = other->_memory[i]->clone();
			else
				this->_memory[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* newMateria)
{
	if (!newMateria)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_memory[i])
		{
			_memory[i] = newMateria;
			return ;
		}
	}
	delete newMateria;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i ++)
		if (_memory[i] && _memory[i]->getType() == type)
			return(_memory[i]->clone());
	return (0);
}
