/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:52:19 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/21 18:59:49 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

int F(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}
//int main(int argc, char **argv)
int main(int argc, char** argv)
{
	if (argc != 2)
		return (1);

	PmergeMe a;

	std::srand(std::time(0));
	int	len = atoi(argv[1]);

	for (int i = 0; i < len; ++i)
	{
		int num = std::rand() % len;
		a.addNums(num);
	}

	
	a.printElements();

	a.merge();

	a.printElements();

	std::cout << "Should be: " << F(len) << std::endl;
	std::cout << "what i did: " << a.getComp() << std::endl;
	return (0);
}
