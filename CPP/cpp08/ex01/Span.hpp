/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:24:06 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/05/23 11:24:11 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

class Span
{
	private:
		size_t				_size;
		size_t				_filled;
		std::vector<int>	_vctr;
		
	public:
		Span();												//	Default constructor will instantiate a 5-element vector.
		Span(unsigned int n);								//	Parametrized constructor instantiates a n-element vector.
		Span(const Span& original);							//	Copy constructor.
		~Span();											//	Destructor.

		Span& operator=(const Span& other);					//	Assignment operator overload.

		void	addNumber(const int number);				//	Member function to add a single number to the Span.
		void	addManyNumbers(const int manyNumbers);		//	Member function to add many numbers to the Span.

		int	shortestSpan();
		int	longestSpan();

		class vectorIsFullException: public std::exception	//	Exception subclass: Full
		{
			const char* what() const throw();
		};
		
		class vectorIsEmptyException: public std::exception	//	Exception subclass: Empty.
		{
			const char* what() const throw();
		};
};	
