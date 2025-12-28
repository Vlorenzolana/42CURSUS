/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:27:27 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:27:29 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



MateriaSource::MateriaSource()
{
	std::cout << "-> MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_page[i] = 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << "-> MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if(_page[i] != 0)
		{
			delete _page[i];
			_page[i] = 0;
		}
	}
}

void MateriaSource::learnMateria(AMateria* spell)
{
	int i = 0;
	while (i < 4 && _page[i] != 0)
		i++;
	if (i < 4)
		_page[i] = spell;
	else
	{
		std::cout << "No more pages in the grimoire!" << std::endl;
		delete spell;
	}
}

AMateria* MateriaSource::createMateria(std::string const& _type)
{
	AMateria* new_materia;
	int i = 0;
	
	while (_page[i] != 0)
	{
		if (_page[i]->getType() == _type)
			break ;
		i++;
	}
	if (i > 3)
		return 0;
	else
		new_materia = _page[i]->clone();
	return new_materia;	
}

