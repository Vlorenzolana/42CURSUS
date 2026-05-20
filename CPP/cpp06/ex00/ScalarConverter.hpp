/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 08:37:51 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/04/08 19:05:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &original);
		~ScalarConverter();
		
		ScalarConverter& operator=(ScalarConverter const &other) const;
		
	protected:
		
	public:	
		static void convert(const std::string &literal);
};

