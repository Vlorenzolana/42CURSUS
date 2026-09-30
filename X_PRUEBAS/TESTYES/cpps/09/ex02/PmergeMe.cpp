/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:46 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/22 20:30:16 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::comparations = 0;

const unsigned int PmergeMe::jacobsthal[] = { 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203 };

PmergeMe::PmergeMe():level(0) {}

PmergeMe::PmergeMe(int newLevel):level(newLevel) {}

PmergeMe::PmergeMe(const PmergeMe& other): listElements(other.listElements){}

PmergeMe::~PmergeMe() {}

int	PmergeMe::getComp()
{
	return (comparations);
}

void	PmergeMe::addNums(int newNum)
{
	std::list<int> temp;
	temp.push_front(newNum);
	listElements.push_back(temp);
}

void	PmergeMe::addElem(std::list<int> newElem)
{
	if (newElem.size() < befListSize)
		return ;

	else if (listElements.size() == 0) //First element of the list
		listElements.push_back(newElem);

	else if (listElements.back().size() == listSize) //Last element FULL
		listElements.push_back(newElem);

	else if (listElements.back().size() < listSize) //Last element NOT FULL
	{
		comparations ++;
		if (listElements.back().back() < newElem.back()) //Gotta merge after
			listElements.back().splice(listElements.back().end(), newElem);
		else
		{
			newElem.splice(newElem.end(), listElements.back()); //Gotta merge bef.
			listElements.back().swap(newElem);
		}
	}
}

void	PmergeMe::merge()
{
	if (listElements.size() < 2)
		return ;
	if (listElements.size() == 2 && listElements.front().size() != listElements.back().size())
		return ;
	
	PmergeMe temp(level + 1);

	myList::iterator	it;
	for (it = listElements.begin(); it != listElements.end(); ++it)
		temp.addElem(*it);

	//printElements();
	temp.merge();
	temp.getChanges(listElements);

	insert();
}

struct CompareListBack
{
	bool operator()(const std::list<int>& a, const std::list<int>& b) const
	{
		PmergeMe::comparations ++;
		return (a.back() < b.back());
	}
};

/*
void	PmergeMe::insert()
{
	myList::iterator	it = ++listElements.begin();
	unsigned int		jacob = 0;
	unsigned int		i = 1;
	
	std::cout << "---------------------------------------" << std::endl;
	while (it != listElements.end() && (*it).size() == listSize)
	{
		
		std::cout << "GroupSize: " << listSize << std::endl;
		std::cout << "Jakovstal: " << jacobsthal[jacob] << std::endl;
		std::cout << "Original: ";
		printElements(listElements);
		myList			pend;
	
		while (i < jacobsthal[jacob])
		{
			if (it == listElements.end() || (*it).size() != listSize)
				break ;
			it ++;
			if (it == listElements.end() || (*it).size() != listSize)
				break ;
			pend.push_front(*it);
			it = listElements.erase(it);
			i ++;
		}
		myList::iterator newIt = it;
		std::cout << "Main: ";
		printElements(listElements.begin(), it);
		std::cout << "Pend: ";
		printElements(pend);
		
		while (!pend.empty())
		{
			myList::iterator begin = listElements.begin();
			begin = std::upper_bound(begin, --newIt, *pend.begin(), CompareListBack());
			listElements.splice(begin, pend, pend.begin());
		}
		jacob ++;
	}
}
*/

/*
		while (i < jacobsthal[jacob])
		{
			if (j == jacobsthal[jacob] - 1)
				limit = it;
			if (j % 2 == 0)
			{
				it ++;
				if (it == listElements.end() || (*it).size() != listSize)
					break ;
			}
			else if (j != 0)
			{
				pend.push_front(*it);
				it = listElements.erase(it);
			}
			i += !(j % 2);
			j ++;
		}
*/

void	PmergeMe::insert()
{
	myList::iterator	it = ++listElements.begin();
	unsigned int		i = 0;
	unsigned int		j = 1;
	unsigned int		t = 0;
	myList::iterator	limitsJac[200];
	myList::iterator	limit;
	myList				pend;
	myList				main;
	
	while (it != listElements.end() && (*it).size() == listSize)
	{
		if (i % 2 == 0)
		{
			main.push_front(*it);
			j ++;
			if (j == jacobsthal[t])
			{
				limitsJac[t] = --main.end();
				t ++;
			}
		}
		else
			pend.push_front(*it);
		it ++;
		i ++;
	}
	std::cout << "Og: ";
	printElements(listElements);
	std::cout << "Main: ";
	printElements(main.begin(), limitsJac[0]);
	std::cout << "Pend: ";
	printElements(pend);
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<";
	j = 0;
	i = 0;
	j = 0;
	while (1)
	{
		while (j < jacobsthal[i])
		{
			if (pend.empty())
			{
				listElements = main;
				return ;
			}
			myList::iterator toInsert = --pend.end();
			myList::iterator insertPos = std::upper_bound(main.begin(), limit, *toInsert, CompareListBack());
			main.splice(insertPos, pend, toInsert);
			limit --;
			j ++;
		}
		i ++;
	}
	listElements = main;
}

/*
		std::cout << "Main: ";
		printElements(listElements.begin(), limit);
		std::cout << "Pend: ";
		printElements(pend);
		std::cout << "<<<<<<<<<<<<<<<<<<<<<<<";
*/

void	PmergeMe::printElements()
{
	myList::iterator it;
	for (it = listElements.begin(); it != listElements.end(); it++)
	{
		myInnerList::iterator ite;
		for (ite = it->begin(); ite != it->end(); ite++)
			std::cout << " " << *ite;
		std::cout << " |";
	}
	std::cout << std::endl;
}

void	PmergeMe::printElements(myList::iterator start, myList::iterator end)
{
	myList::iterator it;
	for (it = start; it != end; it++)
	{
		myInnerList::iterator ite;
		for (ite = it->begin(); ite != it->end(); ite++)
			std::cout << " " << *ite;
		std::cout << " |";
	}
	std::cout << std::endl;
}

void	PmergeMe::printElements(myList& in)
{
	myList::iterator it;
	for (it = in.begin(); it != in.end(); it++)
	{
		myInnerList::iterator ite;
		for (ite = it->begin(); ite != it->end(); ite++)
			std::cout << " " << *ite;
		std::cout << " |";
	}
	std::cout << std::endl;
}

void	PmergeMe::getChanges(std::list<std::list <int> >& elem)
{
	myList&	A(listElements);
	myList&	B(elem);

	myList::iterator	itA;
	myList::iterator	itB = B.begin();

	myInnerList::iterator itInnerA;
	myInnerList::iterator itInnerB = (*itB).begin();

	for (itA = A.begin(); itA != A.end(); itA++)
	{
		for (itInnerA = (*itA).begin(); itInnerA != (*itA).end(); itInnerA++)
		{
			*itInnerB = *itInnerA;
			if (++itInnerB == (*itB).end())
				itInnerB = (*(++itB)).begin();
		}
	}
}

PmergeMe&	PmergeMe::operator = (const PmergeMe& other)
{
	if (this != &other)
	{

	}
	return (*this);
}

/*
7 4 9 0 1 2 8 3 5

4 7 0 9 | 1 2 3 8 5

b1    a1    b2    a2
1 2 | 3 8 | 4 7 | 0 9 | 5

main: 1 2 | 3 8 | 0 9
pend: 4 7
     _____
1 2 | 4 7 | 3 8 | 0 9

b1  a1  b2  a2  b3  a3  b4  a4  b5
1 | 2 | 4 | 7 | 3 | 8 | 0 | 9 | 5

main: 1 | 2 | 7 | 8 | 9
pend: 4 | 3 | 0 | 5
*/
