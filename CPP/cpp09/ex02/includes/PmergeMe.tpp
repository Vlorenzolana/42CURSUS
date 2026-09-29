/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:38:21 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::MIS(T& container, double& lapse)
{
	T		large;
	T		small;
	clock_t	start;
	clock_t	end;

	if (container.size() <= 1)
		return;

	start = clock();

	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
		{
			large.push_back(container[i]);
			small.push_back(container[i + 1]);
		}
		else
		{
			large.push_back(container[i + 1]);
			small.push_back(container[i]);
		}
	}

	if (container.size() % 2 != 0)
		small.push_back(container.back());

	MIS(large, lapse);
	MIS(small, lapse);

	for (size_t i = 0; i < small.size(); i++)
	{
		typename T::iterator it = large.begin();
		while (it != large.end() && *it < small[i])
			it++;
		large.insert(it, small[i]);
	}
	end = clock();
	container = large;
	lapse = ((end - start) * (double)1000) / CLOCKS_PER_SEC;
}
