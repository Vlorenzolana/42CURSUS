/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:52:11 by vlorenzo           #+#    #+#             */
/*   Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		double				_lapseVector;
		double				_lapseDeque;
		PmergeMe();										//	No instantiation before input is validated
	
	public:
		PmergeMe(const std::vector<int>& input);		//	Custom parametrized constructor
		PmergeMe(const PmergeMe& original);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	MergeInsertionSort();
		template <typename T>
		void MIS(T& container, double& lapse);
		
		std::vector<int>	getResult();
		double 				getLapseVector() const;
		double 				getLapseDeque() const;
};

bool				validateArguments(const int argc, char** argv);
std::vector<int>	createUnsortedVector(const int argc, char** argv);
void				showBefore(const std::vector<int>& unsorted);
void				showAfter(const std::vector<int>& sorted);

#include "PmergeMe.tpp"

