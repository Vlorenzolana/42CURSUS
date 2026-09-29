/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:02:00 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/09/29 19:02:03 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>

class RPN
{
	private:
		bool	isOperator(const std::string &token) const;
		int		applyOperation(int a, int b, const std::string &op) const;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int	evaluate(const std::string &expr) const;
};


#endif
