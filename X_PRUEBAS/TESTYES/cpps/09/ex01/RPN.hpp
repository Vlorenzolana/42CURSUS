/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:04:35 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/26 14:28:30 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;
		
	public:
		RPN();
		RPN(const RPN& other);
		~RPN();

		void add(char input);

		int getRes();

		RPN&	operator = (const RPN& other);
};

#endif