/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:39:48 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/28 19:03:51 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T*				_arr;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		unsigned int size() const;

		T&			operator [] (unsigned int n);
		const T&	operator [] (unsigned int n) const;
		Array&		operator = (const Array& other);
};

#include "Array.tpp"

#endif
