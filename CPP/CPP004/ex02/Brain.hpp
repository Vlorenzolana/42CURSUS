/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:23:34 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/26 16:23:36 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
	
	public:

		std::string ideas[100];
		
		Brain();
		Brain(const Brain& model);
		~Brain();

		Brain& operator=(const Brain& other);
};
