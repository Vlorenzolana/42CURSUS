/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:21:44 by kabasolo          #+#    #+#             */
/*   Updated: 2025/05/13 13:14:57 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator	iterator;

		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();

		iterator begin();
		iterator end();

		MutantStack&	operator = (const MutantStack& other);
};

#include "MutantStack.tpp"

#endif