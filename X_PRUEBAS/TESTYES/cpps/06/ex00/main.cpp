/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:08:40 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/18 12:17:50 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
		return (ScalarConverter::convert(argv[1]), 0);
	std::cout << "Error: Bad argc" << std::endl;
	return (1);
}
