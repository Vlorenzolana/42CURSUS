/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/20 17:41:15 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
	private:
		std::vector<int>	_nums;
		unsigned int		_size;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		~Span();

		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		Span&	operator = (const Span& other);
};

#endif