/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 08:43:49 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/04/08 19:05:43 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &original);
		~Serializer();
		Serializer& operator=(const Serializer &other) const;
	
	protected:
	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

