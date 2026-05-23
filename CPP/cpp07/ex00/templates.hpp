/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:25:51 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 14:03:56 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T&	min(T &a, T &b) // T& change the OG values in swap
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T&	max(T &a, T &b)
{
	if (a > b)
		return a;
	else
		return b;
}