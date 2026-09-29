/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:19:09 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/05/22 19:45:46 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Iter.hpp"

template <typename T>
void	print(const T &x)
{
	std::cout << x << " ";
}

void	capitalize(char &c)
{
	c = std::toupper(c);
}

void	increment(int &n)
{
	n += 1;
}

int	main()
{
	int			array[5] = {1, 2, 3, 4, 5};
	const int	constArray[5] = {10, 20, 30, 40, 50};
	char		charArray[6] = "world";

	std::cout << "Array int: ";
	iter(array, 5, print<int>);
	std::cout << std::endl;

	iter(array, 5, increment);
	std::cout << "Array int after increment: ";
	iter(array, 5, print<int>);
	std::cout << std::endl;
	
	std::cout << "Const array int: ";
	iter(constArray, 5, print<int>);
	std::cout << std::endl;

	std::cout << "Array char before: ";
	iter(charArray, 5, print<char>);
	std::cout << std::endl;

	iter(charArray, 5, capitalize);

	std::cout << "Array char after capitalize: ";
	iter(charArray, 5, print<char>);
	std::cout << std::endl;

	return 0;
}
