/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:27:11 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:27:13 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define ICHARACTER_HPP

# include <iostream>
class AMateria;												//	This is a forward declaration. No need to explicitly include AMateria, only state that it exists.

class ICharacter
{
	private:
		ICharacter(const ICharacter& original);
		ICharacter& operator=(const ICharacter& other);
	
	protected:
		ICharacter() {};
	
	public:
		virtual ~ICharacter() {};							//	Public declaration of destructor is crucial for proper polymorphic cleanup when deleting objects through a base pointer.
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

