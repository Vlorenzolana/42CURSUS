/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:26:43 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:26:46 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
# include "AMateria.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::~Character()
{
	std::cout << "-> Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != 0)
			delete _inventory[i];
	}
}

Character::Character(const Character& original)
{
	std::cout << "-> Character copy constructor called" << std::endl;
	_name = original._name;
	for (int i = 0; i < 4; i++)
	{
		if (original._inventory[i] != 0)
			_inventory[i] = original._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character::Character(std::string const& name)
{
	std::cout << "-> Character parametrized constructor called" << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

std::string const& Character::getName() const
{
	return _name;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "-> Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] != 0)
			{
				delete _inventory[i];
				_inventory[i] = 0;
			}
			if (other._inventory[i] != 0)
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			std::cout << m->getType() << " equipped!" << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (_inventory[idx] != 0)
	{
		delete _inventory[idx];
		_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx] != 0)
		_inventory[idx]->use(target);
}