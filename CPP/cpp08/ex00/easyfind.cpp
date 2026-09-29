/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:41:38 by vlorenzo          #+#    #+#             */
/*   Updated: 2026/06/28 19:41:40 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>
#include <iterator>

template <typename T>
size_t easyfind(const std::vector<T>& myvector, const T& target)
{
	typename std::vector<T>::const_iterator it = std::find(myvector.begin(), myvector.end(), target);
	    
	if (it != myvector.end())									
		return (std::distance(myvector.begin(), it));

	throw std::runtime_error("Exception: Target value not found");
}

