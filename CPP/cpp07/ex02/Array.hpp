/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:25:22 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 11:25:25 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T       *array;
        size_t  _size;

    protected:

    public:
       
        Array();
        Array(unsigned int n);
        Array(const Array& original);
        ~Array();

        Array& operator=(const Array& other);
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        
        size_t getSize() const;
};

#include "Array.tpp"	//	This is the key. It "brings" the template instruction here. 