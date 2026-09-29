/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:43:54 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/09/29 18:49:02 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN2_HPP
#define SPAN2_HPP

#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int number);
		long long shortestSpan() const;
		long long longestSpan() const;

		template <typename T>
		
		void addRange(T begin, T end)
		{
			if(_numbers.size() + std::distance(begin, end) > _N)
				throw std::runtime_error("Not enough space");
			for (T it = begin; it != end; ++it)
				_numbers.push_back(*it);
		}
};

#endif