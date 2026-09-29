/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:21:31 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 12:45:34 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MutantStack.tpp"
#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack: public std::stack<T>
{
	private:
	
	protected:
	
	public:
		MutantStack();
		MutantStack(const MutantStack& original);
		~MutantStack();

		MutantStack& operator=(const MutantStack& other);

		// typename MutantStack<T>::container_type::iterator iterator;				//	This is the full verbose version of the type
		typedef typename MutantStack<T>::container_type::iterator iterator;			//	Instead of writing the full verbose type each time, alias it.
		iterator begin();															//	Profit! :o)
		iterator end();
		
		// typename MutantStack<T>::container_type::reverse_iterator rev_reverse_iterator;
		typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();
		
		// typename MutantStack<T>::container_type::const_iterator const_iterator;
		typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
		
		// typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};