/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:38:02 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/28 11:49:43 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _arr(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _arr(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other): _arr(new T[other.size()]), _size(other.size())
{
	for (unsigned int i = 0; i < _size; i ++)
		this->_arr[i] = other._arr[i];
}

template <typename T>
Array<T>::~Array() {delete[] _arr;}

template <typename T>
unsigned int	Array<T>::size() const {return (_size);}

template <typename T>
T&	Array<T>::operator [] (unsigned int n)
{
	if (n >= _size)
		throw std::out_of_range("Index out of range");
	return (_arr[n]);
}

template <typename T>
const T&	Array<T>::operator [] (unsigned int n) const
{
	if (n >= _size)
	throw std::out_of_range("Index out of range");
	return (_arr[n]);
}

template <typename T>
Array<T>&	Array<T>::operator = (const Array& other)
{
	if (this != &other)
	{
		delete[] _arr;
		this->_size = other._size;
		this->_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i ++)
			this->_arr[i] = other._arr[i];
	}
	return (*this);
}
