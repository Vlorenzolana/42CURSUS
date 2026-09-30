/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:47:29 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/19 12:02:19 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) 
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T& min(T& a, T& b)
{
	return (a < b) ? a : b;
}

template <typename T>
T& max(T& a, T& b)
{
	return (a > b) ? a : b;
}

#endif