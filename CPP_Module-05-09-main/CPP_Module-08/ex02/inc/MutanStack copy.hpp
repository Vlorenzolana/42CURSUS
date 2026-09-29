/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack copy.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:50:44 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/09/29 18:49:08 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutanStack : public std::stack<T>
{
	public:
		MutanStack() : std::stack<T>() {}
		MutanStack(const MutanStack& other) : std::stack<T>(other) {}
		~MutanStack() {}

		MutanStack& operator=(const MutanStack& other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{
			return this -> c.begin();
		}
		
		iterator end()
		{
			return this -> c.end();
		}

		void	push(const T& value)
		{
			std::stack<T>::push(value);
		}

		void	pop()
		{
			std::stack<T>::pop();
		}

		T& top()
		{
			return std::stack<T>::top();
		}

		const T& top() const
		{
			return std::stack<T>::top();
		}

		size_t size() const
		{
			return std::stack<T>::size();
		}
};

#endif