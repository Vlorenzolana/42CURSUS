/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:08:20 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T, typename Func>
void	iter(T *address, unsigned int len, Func f)
{
	for (unsigned int i = 0; i < len; i++)
	{
		f(address[i]);
	}
}

template< typename T >
void	printer(const T& to_be_printed)
{
	std::cout << to_be_printed << std::endl;
}

template< typename T >
void	incrementer(T& element)
{
	element++;
}